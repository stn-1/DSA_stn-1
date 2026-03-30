#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_LINE 80

int main(void) {
    char *args[MAX_LINE/2 + 1];
    char input[MAX_LINE];
    char last_command[MAX_LINE] = "";
    int should_run = 1;

    while (should_run) {
        printf("osh>");
        fflush(stdout);

        if (fgets(input, MAX_LINE, stdin) == NULL) break;
        input[strcspn(input, "\n")] = '\0'; // Xóa ký tự xuống dòng

        // Xử lý History !!
        if (strcmp(input, "!!") == 0) {
            if (strlen(last_command) == 0) {
                printf("No commands in history.\n");
                continue;
            }
            strcpy(input, last_command);
            printf("%s\n", input);
        } else {
            strcpy(last_command, input);
        }

        if (strcmp(input, "exit") == 0) {
            should_run = 0;
            continue;
        }

        // Tách chuỗi thành tokens
        int i = 0;
        char *token = strtok(input, " ");
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        // Kiểm tra chạy ngầm &
        int background = 0;
        if (i > 0 && strcmp(args[i-1], "&") == 0) {
            background = 1;
            args[i-1] = NULL;
        }

        pid_t pid = fork();
        if (pid == 0) { // Tiến trình con
            // Xử lý Redirection và Pipe ở đây
            for (int j = 0; args[j] != NULL; j++) {
                if (strcmp(args[j], ">") == 0) {
                    int fd = open(args[j+1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
                    dup2(fd, STDOUT_FILENO);
                    close(fd);
                    args[j] = NULL;
                } else if (strcmp(args[j], "<") == 0) {
                    int fd = open(args[j+1], O_RDONLY);
                    if (fd < 0) { perror("File error"); exit(1); }
                    dup2(fd, STDIN_FILENO);
                    close(fd);
                    args[j] = NULL;
                }
            }
            
            execvp(args[0], args);
            printf("Error executing command\n");
            exit(1);
        } else { // Tiến trình cha
            if (!background) waitpid(pid, NULL, 0);
        }
    }
    return 0;
}