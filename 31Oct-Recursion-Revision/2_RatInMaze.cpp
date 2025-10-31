#include <iostream>
using namespace std;

bool ratInMaze(char maze[][10], int i, int j, int sol[][10], int n, int m) {
	// Base case
	if (i == n - 1 and j == m - 1) { // mill gaya solution
		sol[i][j] = 1; // base case bhi toh sol ka part hoga hi...
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cout << sol[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		return false;
	}
	// Recursive case
	sol[i][j] = 1; // Assume karlo i,j wala cell answer hai

	// 1. Right se dekhte hai pehle, agr right se raasta mill gaya toh done...
	if (j + 1 < m and maze[i][j + 1] != 'X') {
		bool kyaMilla = ratInMaze(maze, i, j + 1, sol, n, m);
		if (kyaMilla == true) {
			return true;
		}
	}
	// 2. Down se dekhte hai then if right se raasta nhi milta toh, if milla toh done..
	if (i + 1 < n and maze[i + 1][j] != 'X') {
		bool kyaMilla = ratInMaze(maze, i + 1, j, sol, n, m);
		if (kyaMilla == true) {
			return true;
		}
	}

	sol[i][j] = 0; // backtracking
	return false;
}

int main() {

	char maze[][10] = {
		"0000",
		"00XX",
		"0000",
		"XX00",
	};
	int sol[10][10] = {0};

	ratInMaze(maze, 0, 0, sol, 4, 4);

	return 0;
}








