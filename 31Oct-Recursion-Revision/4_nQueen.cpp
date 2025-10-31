#include <iostream>
using namespace std;

bool safeHai(int board[][10], int i, int j, int n) {
	// check upar ke rows
	for (int k = 0; k < i; ++k)
	{
		if (board[k][j] == 1) {
			return false;
		}
	}
	int copy_i = i, copy_j = j;
	// Check upper right diagonal
	while (i >= 0 and j < n) {
		if (board[i][j] == 1) {
			return false;
		}
		i--;
		j++;
	}
	// Check upper left diagonal
	i = copy_i;
	j = copy_j;
	while (i >= 0 and j >= 0) {
		if (board[i][j] == 1) {
			return false;
		}
		i--;
		j--;
	}

	return true;
}

bool nqueen(int board[][10], int i, int n) {
	// base case
	if (i == n) {
		// Print the board
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}

		return true;
	}

	// recursive case
	// ith row mei merko queen place krni h
	// saare column par ek ek krke check krna hai place krna safe hai?
	for (int j = 0; j < n; ++j)
	{
		if (safeHai(board, i, j, n) == true) {
			board[i][j] = 1; // queen rakhdi ek meine
			bool kyaBakiPlaceHui = nqueen(board, i + 1, n);
			if (kyaBakiPlaceHui == true) {
				return true;
			}

			board[i][j] = 0; // backtracking
		}
	}

	// means kisi bhi column mei queen nhi rakh paye
	return false;
}

int main() {

	int board[10][10] = {};
	nqueen(board, 0, 5);

	return 0;
}
















