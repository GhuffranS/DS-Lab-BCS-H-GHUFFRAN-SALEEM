#include <iostream>
using namespace std;

#define N 4

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j]) return false;

    return true;
}

bool solveNQUtil(int board[N][N], int row) {
    if (row >= N) {
        printSolution(board);
        return true;
    }
    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, row, i)) {
            board[row][i] = 1;
            res = solveNQUtil(board, row + 1) || res;
            board[row][i] = 0;
        }
    }
    return res;
}

int main() {
    int board[N][N] = {0};
    if (!solveNQUtil(board, 0)) cout << "No solution";
    return 0;
}
