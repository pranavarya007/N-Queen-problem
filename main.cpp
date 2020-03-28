/* to change the value of n just change N in #define N*/

#include <iostream>
#include <bits/stdc++.h>
#define N 5

using namespace std;

void print_board(int board[N][N]) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool is_safe(int board[N][N], int row , int col) {
    for (int i=0; i<col; i++) {
        if (board[row][i])
            return false;
    }
    for (int i=row, j=col; i>=0 && j>=0; i--,j--) {
        if (board[i][j])
            return false;
    }
    for (int i=row, j=col; i<N && j>=0; i++,j--) {
        if (board[i][j])
            return false;
    }
    return true;
}
///utility function
bool util(int board[N][N], int col) {
    if (col>=N)
        return true;
    for (int i=0; i<N; i++) {
        if (is_safe(board, i, col)) {
            board[i][col] = 1;

            if (util(board, col+1))
                return true;
            board[i][col] = 0;  ///backtrack
        }
    }
    return false;
}
bool solveNQ() {
    int board[N][N] = {{0 , 0, 0, 0, 0},
                       {0 , 0, 0, 0, 0},
                       {0 , 0, 0, 0, 0},
                       {0 , 0, 0, 0, 0},
                       {0 , 0, 0, 0, 0}};
    if (util(board, 0) == false) {
        cout<<"solution does not exist"<<endl;
        return false;
    }
    print_board(board);
    return true;
}

int main()
{
    solveNQ();
    return 0;
}
