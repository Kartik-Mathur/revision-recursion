#include <iostream>
#include <cmath>
using namespace std;

bool isSafe(int mat[][9], int i, int j, int no, int n) {
	// Check row and column......
	for (int k = 0; k < n; ++k)
	{
		if (mat[i][k] == no or mat[k][j] == no) {
			return false;
		}
	}

	// Chota box
	n = sqrt(n);
	int si = (i / n) * n;
	int sj = (j / n) * n;

	for (int i = si; i < si + n; ++i)
	{
		for (int j = sj; j < sj + n; ++j)
		{
			if (mat[i][j] == no) {
				return false;
			}
		}
	}

	return true;
}

bool sudokuSolver(int mat[][9], int i, int j, int n) {
	// base case
	if (i == n) {
		// print sudoku
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}

		return false;
	}

	// recursive case
	if (j == n) { // agar ek row fill ho gai toh next row par jaane ko bolo
		return sudokuSolver(mat, i + 1, 0, n);
	}

	// 1. Filled Cell(Hum recursion ko bolna hai batade, we cant change this val)
	if (mat[i][j] != 0) {
		bool kyaBakiSolveHua = sudokuSolver(mat, i, j + 1, n);
		// i,j wala cell hum change kr nhi skte toh jo rec ne bola whi hoga final
		return kyaBakiSolveHua;
	}

	// 2. Empty cell
	for (int no = 1; no <= n; ++no)
	{
		if (isSafe(mat, i, j, no, n) == true) {
			mat[i][j] = no; // safe hai toh is empty cell par no rakho
			bool kyaBakiSolveHua = sudokuSolver(mat, i, j + 1, n); // baaki rec se pucho
			if (kyaBakiSolveHua == true) {
				return true; // baaki ka sudoku bhi solve ho gaya....
			}

			// toh bhai i,j par no ke sath baat nhi bani hatado isse
			mat[i][j] = 0; // backtracking
		}
	}

	// loop se bahar ka meaning koi 1,n number place nhi hua at i,j
	return false;
}

int main() {
	int mat[9][9] = {
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	};

	sudokuSolver(mat, 0, 0, 9);
	return 0;
}
















