
#include <bits/stdc++.h>
using namespace std;

int COL;
int ROW;
int N = 4;

// Prints the final chessboard
void printSolution(vector<vector<int>> board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            if (board[i][j])
                cout << "Q ";  // Queen is placed
            else
                cout << ". ";  // Empty cell

        cout << endl;
    }
}

// Checks whether placing a queen at (row, col) is safe
bool isSafe(vector<vector<int>> board, int row, int col) {
    int i, j;

    // Check the left side of the current row
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check the right side of the current row
    for (i = col + 1; i < N; i++)
        if (board[row][i])
            return false;

    // Check bottom-right diagonal
    for (i = row, j = col; i < N && j < N; i++, j++)
        if (board[i][j])
            return false;

    // Check top-right diagonal
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    // Check top-left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check bottom-left diagonal
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    // No other queen attacks this position
    return true;
}

// Recursive function to place queens column by column
bool solveNQUtil(vector<vector<int>> &board, int col) {

    // Base condition: all columns are processed
    // N queens have been placed successfully
    if (col >= N)
        return true;

    // Skip the column where the first queen is already placed
    if (col == COL) {
        if (solveNQUtil(board, col + 1))
            return true;
        else
            return false;
    }

    else {
        // Try placing a queen in every row of the current column
        for (int i = 0; i < N; i++) {

            // Place queen only if the position is safe
            if (isSafe(board, i, col)) {

                board[i][col] = 1;  // Place queen

                // Recursively solve the next column
                if (solveNQUtil(board, col + 1))
                    return true;

                // Backtrack: remove queen if solution is not found
                board[i][col] = 0;
            }
        }
    }

    // No valid position found in this column
    return false;
}

bool solveNQ() {

    cout << "Enter size of board: ";
    cin >> N;

    cout << "Enter row and col of first queen to be placed:\n";
    cout << "row (1-" << N << "): ";
    cin >> ROW;
    ROW--;

    cout << "\ncol(1-" << N << "): ";
    cin >> COL;
    COL--;

    cout << endl;

    // Create an N x N board filled with zeroes
    vector<vector<int>> board(N, vector<int>(N, 0));

    // Place the first queen at the user-given position
    board[ROW][COL] = 1;

    // Start solving from column 0
    if (solveNQUtil(board, 0) == false) {
        cout << "Solution does not exist";
        return false;
    }

    // Print the board if a solution is found
    printSolution(board);

    return true;
}

int main() {
    solveNQ();
    return 0;
}
