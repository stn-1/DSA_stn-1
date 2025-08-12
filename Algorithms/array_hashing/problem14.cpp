#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
 bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9),col(9),sub_board(9);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                char val = board[i][j];
                if(val=='.') continue;
                //kiểm tra row
                if (row[i].count(val)) return false;
                row[i].insert(val);
                // kiểm tra col
                if (col[j].count(val)) return false;
                col[j].insert(val);
                //kiểm tra sub_board
                int boxIndex = (i / 3) * 3 + (j / 3);
                if(sub_board[boxIndex].count(val)) return false;
                sub_board[boxIndex].insert(val);
            }
        }
        return true;
    }
int main(){
    vector<vector<char>> board = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
};
cout<<isValidSudoku(board);
    return 0;
}