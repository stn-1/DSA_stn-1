#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        while (left < right && s[left] == ' ') left++;
        while (left < right && s[right] == ' ') right--;

        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    string s = "Was it a car or a cat I saw";
    cout << isPalindrome(s);
}
