/* 
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
"." means empty cell.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm> 
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set <string> st;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                string row=string(1,board[i][j]) + "_ROW_" + to_string(i);
                string col=string(1,board[i][j]) + "_COL_" + to_string(j);
                string box=string(1,board[i][j]) + "_BOX_" + to_string(i/3) + "_" + to_string(j/3);

                if(st.find(row)!= st.end() || st.find(col)!= st.end() || st.find(box)!= st.end()){
                    return false;

                }
                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }
    return true; 
    }
};