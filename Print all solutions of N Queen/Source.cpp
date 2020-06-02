#include <bits/stdc++.h>
using namespace std;
int N,ct=1;
void print_board(int** board) {
	cout << endl;
	cout << "         Solution : " << ct << endl;
	for (int i = 0; i < N; i++) {
		cout << "                        ";
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	ct++;
}

bool is_safe(int** board, int row, int col) {
	for (int i = 0; i < row; i++) {
		if (board[i][col])
			return false;
	}
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j])
			return false;
	}
	for (int i = row, j = col; j < N && i >= 0; i--, j++) {
		if (board[i][j])
			return false;
	}
	return true;
}
///utility function
void solveNQ(int** board, int r)
{
	if (r == N) {
		print_board(board);
		return;
	}

	for (int i = 0; i < N; i++) {
		 if (is_safe(board, r, i)) {
			board[r][i] = 1;
			solveNQ(board, r + 1);
			board[r][i] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << "Enter the size of the board :  ";
	cin >> N;
	cout << endl;
	int** board = new int* [N];
	for (int i = 0; i < N; ++i)
		board[i] = new int[N];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = 0;
		}
	}
	cout << "1 represents the position of the queen and 0 represens Null position or empty block." << endl;
	solveNQ(board, 0);
	cout << endl;
	return 0;
}