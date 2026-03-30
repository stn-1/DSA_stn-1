#include <iostream>
#include <limits>
using namespace std;

bool End = false;
bool Draw = false;

class Tables {
public:
    int cols;
    int rows;
    char** Table;

    Tables() : cols(0), rows(0), Table(nullptr) {}

    void Enter_Table() {
        do {
            cout << "Enter the number of columns: ";
            cin >> cols;
            cout << "Enter the number of rows: ";
            cin >> rows;
            if (cols < 5 || rows < 5) cout << "This table cannot be used for playing!" << endl;
        } while (cols < 5 || rows < 5);

        cout << "Table created successfully!" << endl;

        Table = new char* [rows];
        for (int i = 0; i < rows; i++) {
            Table[i] = new char[cols];
            for (int j = 0; j < cols; j++) {
                Table[i][j] = '_';
            }
        }
    }

    ~Tables() {
        for (int i = 0; i < rows; ++i) {
            delete[] Table[i];
        }
        delete[] Table;
    }

    void Show_Table() {
        Draw = true;
        cout << "  ";
        for (int j = 0; j < cols; ++j) cout << j << " ";
        cout << endl;
        for (int i = 0; i < rows; ++i) {
            cout << i << " ";
            for (int j = 0; j < cols; ++j) {
                cout << Table[i][j] << " ";
                if (Table[i][j] == '_') Draw = false;
            }
            cout << endl;
        }
    }

    void Play_and_Check() {
        int a, b;
        char c;

        cout << "You are (X or O): ";
        cin >> c;

        cout << "Enter your move (row column): ";
        cin >> a >> b;

        if (cin.fail() || a < 0 || a >= rows || b < 0 || b >= cols) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid move. Please enter valid numbers within bounds!" << endl;
            return;
        }

        if (Table[a][b] != '_') {
            cout << "This cell is already taken!" << endl;
            return;
        }

        Table[a][b] = c;

        // Horizontal check
        int check = 1, i = 1;
        while (b - i >= 0 && Table[a][b - i] == c) { check++; i++; }
        i = 1;
        while (b + i < cols && Table[a][b + i] == c) { check++; i++; }
        if (check >= 5) {
            cout << c << " wins! (horizontal)" << endl;
            End = true;
            return;
        }

        // Vertical check
        check = 1; i = 1;
        while (a - i >= 0 && Table[a - i][b] == c) { check++; i++; }
        i = 1;
        while (a + i < rows && Table[a + i][b] == c) { check++; i++; }
        if (check >= 5) {
            cout << c << " wins! (vertical)" << endl;
            End = true;
            return;
        }

        // Diagonal /
        check = 1; i = 1;
        while (a - i >= 0 && b + i < cols && Table[a - i][b + i] == c) { check++; i++; }
        i = 1;
        while (a + i < rows && b - i >= 0 && Table[a + i][b - i] == c) { check++; i++; }
        if (check >= 5) {
            cout << c << " wins! (diagonal /)" << endl;
            End = true;
            return;
        }

        // Diagonal \
        check = 1; i = 1;
        while (a - i >= 0 && b - i >= 0 && Table[a - i][b - i] == c) { check++; i++; }
        i = 1;
        while (a + i < rows && b + i < cols && Table[a + i][b + i] == c) { check++; i++; }
        if (check >= 5) {
            cout << c << " wins! (diagonal \\)" << endl;
            End = true;
            return;
        }
    }
};

int main() {
    Tables x;
    x.Enter_Table();
    while (!End) {
        x.Play_and_Check();
        x.Show_Table();
        if (Draw) {
            cout << "It's a draw!" << endl;
            break;
        }
    }
    return 0;
}
