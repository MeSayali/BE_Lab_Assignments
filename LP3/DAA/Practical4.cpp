
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

bool solve(vector<vector<int>>& board, int row, int n) {
    if (row == n)
        return true;

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;

            if (solve(board, row + 1, n))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size\n";
        return 0;
    }

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solve(board, 0, n)) {
        for (auto& row : board) {
            for (int cell : row)
                cout << cell << " ";
            cout << "\n";
        }
    } else {
        cout << "No solution exists\n";
    }

    return 0;
}
