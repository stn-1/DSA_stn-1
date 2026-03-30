#include <iostream>  
#include <random>  
#include <set>  
#include <utility>  
using namespace std;

class Tables {
public:
    int cols;
    int rows;
    char** Table;
    set<pair<int, int>> Boom_Location;
    bool lose = false;
    //enter the table use dynamic 2D array
    void Enter_Table(int r, int c) {                                                                
        rows = r;
        cols = c;
        Table = new char* [rows];
        for (int i = 0; i < rows; i++) {
            Table[i] = new char[cols];
            for (int j = 0; j < cols; j++) {
                Table[i][j] = '_';
            }
        }
    }
    //set boom use random and save the location of boom using set and pair
    void Set_Boom(int numBooms) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> disRow(0, rows - 1);
        uniform_int_distribution<> disCol(0, cols - 1);

        int placedBooms = 0;
        while (placedBooms < numBooms) {
            int row = disRow(gen);
            int col = disCol(gen);

            if (Boom_Location.find({ row, col }) == Boom_Location.end()) {
                Boom_Location.insert({ row, col });
                placedBooms++;
            }
        }
    }
    // use destructor to avoid memory leaks
    ~Tables() {
        if (Table) {
            for (int i = 0; i < rows; ++i) {
                delete[] Table[i];
            }
            delete[] Table;
        }
    }
    // show table and check win condition
    void Show_Table() {
        int check = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << Table[i][j] << " ";
                if (Table[i][j] == '_') check++;
            }
            cout << endl;
        }
        if (check == 0) { 
            cout << "You win!" << endl;
        }
    }
    // a function check around and enter the number of boom in table[x][y]
    void Surrounding_Booms(int x, int y) {
        int number_booms = 0;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;

                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                    if (Boom_Location.find({ nx, ny }) != Boom_Location.end()) {
                        number_booms++;
                    }
                }
            }
        }
        Table[x][y] = number_booms + '0';
    }
    // a function use Surrounding_Booms to expand zero
    void expandZero(int x, int y) {
        if (Boom_Location.find({ x, y }) != Boom_Location.end()) {
            cout << "Boooom! You lose." << endl;
            lose = true;
            return;
        }

        Surrounding_Booms(x, y);

        if (Table[x][y] == '0') {
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 && dy == 0) continue;

                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && Table[nx][ny] == '_') {
                        expandZero(nx, ny);   //recursive

                    }
                }
            }
        }
    }
};
// start game
void startGame(Tables& game, int rows, int cols, int numBooms) {
    game.Enter_Table(rows, cols);
    game.Set_Boom(numBooms);

    while (!game.lose) { 
        int row, col;
        cout << "Enter your move (row, col): ";
        cin >> row >> col;

        if (row < 0 || row >= game.rows || col < 0 || col >= game.cols) {
            cout << "Invalid position! Try again." << endl;
            continue;
        }

        game.expandZero(row, col);
        game.Show_Table(); // Hiển thị bảng sau mỗi lần nhập

        if (game.lose) {
            cout << "Game over!" << endl;
        }
    }
}

// Repeat the game
bool askToPlayAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

int main() {
    do {
        Tables game;
        int player_choose;

        cout << "Welcome to Minesweeper game!" << endl;
        cout << "Choose your option" << endl;
        cout << "1. Easy" << endl;
        cout << "2. Normal" << endl;
        cout << "3. Hard" << endl;
        cout << "4. Exit" << endl;

        do {
            cin >> player_choose;
            if (player_choose == 1) {
                startGame(game, 9, 9, 10);
            }
            else if (player_choose == 2) {
                startGame(game, 16, 16, 40);
            }
            else if (player_choose == 3) {
                startGame(game, 24, 24, 99);
            }
            else if (player_choose == 4) {
                cout << "Goodbye!" << endl;
            }
            else {
                cout << "Invalid choice, please try again." << endl;
            }
        } while (player_choose < 1 || player_choose > 4);

    } while (askToPlayAgain()); // Ask player do you want to play again

    return 0;
}
