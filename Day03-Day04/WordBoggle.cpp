#include <bits/stdc++.h>
using namespace std;

template <typename T>
void printMatrix(vector<vector<T>> &matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }
}

bool isSafe(vector<vector<char>> & board, int r, int c, int row, int col, string & word, int index) {
    if (r < 0 || r >= row || c < 0 || c >= col || board[r][c] != word[index])
        return false;
    else
        return true;
}

#define POSSIBLE_MOVES 4
vector<int> xMoves = {0, 1, 0, -1};
vector<int> yMoves = {1, 0, -1, 0};

bool wordExistsHelper(vector<vector<char>> &board, int x, int y, int &row, int &col, string &word, int index) {
    if (index >= word.size()) {
        return true;
    }

    if (isSafe(board, x, y, row, col, word, index)) {
        char c = board[x][y];
        board[x][y] = '*';

        int nextX, nextY;
        for (int i = 0; i < POSSIBLE_MOVES; i++) {
            nextX = x + xMoves[i];
            nextY = y + yMoves[i];
            if (wordExistsHelper(board, nextX, nextY, row, col, word, index + 1)) {
                return true;
            }
        }
        board[x][y] = c;
    }
    return false;
}

bool wordExists(vector<vector<char>> & board, int row, int col, string & word) {
    if (word.empty()) {
        return true;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (wordExistsHelper(board, i, j, row, col, word, 0)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int testCases, row, col;
    string word;
    cin >> testCases;
    while (testCases > 0)
    {
        testCases--;
        cin >> row >> col;
        vector<vector<char>> board(row, vector<char>(col));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> board[i][j];
            }
        }
        cin >> word;

        cout << wordExists(board, row, col, word) << endl;
        
        // your function
    }
}