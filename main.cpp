#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
void print_board(int **board) {
	for (int i = 0; i < N; i++) {
		cout << "                   ";
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

bool is_safe(int **board, int row, int col) {
	for (int i = 0; i < col; i++) {
		if (board[row][i])
			return false;
	}
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j])
			return false;
	}
	for (int i = row, j = col; i < N && j >= 0; i++, j--) {
		if (board[i][j])
			return false;
	}
	return true;
}
///utility function
bool util(int **board, int col) {
	if (col >= N)
		return true;
	for (int i = 0; i < N; i++) {
		if (is_safe(board, i, col)) {
			board[i][col] = 1;

			if (util(board, col + 1))
				return true;
			board[i][col] = 0;  ///backtrack
		}
	}
	return false;
}
bool solveNQ() {
	cout << "Enter the number of queens   ";
	cin >> N;
	cout << endl;
	int** board = new int* [N]; // each element is a pointer to an array.

	for (int i = 0; i < N; ++i)
		board[i] = new int[N];
	//memset(board, 0, sizeof(board));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = 0;
		}
	}
	if (util(board, 0) == false) {
		cout << "solution does not exist" << endl;
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
