#include <iostream>
using namespace std;

bool ratInMaze(char maze[][5], int sol[][10], int i, int j, int n, int m) {
	// base case
	// Agr destination par hi khade ho toh maze solve krne ki need nhi hai
	if (i == n - 1 and j == m - 1) {
		sol[i][j] = 1;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cout << sol[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		// Fool the recursion by telling abhi bhi des par nhi pahunche toh it will
		// keep finding all the solutions
		return false;
	}

	// recursive case
	sol[i][j] = 1; // jis cell par khade hai usse sol ka part maan lia....

	// 1. Is i,j cell se right jaakar choti problem recursion ko bolo bataye solve ho paai
	if (j + 1 < m and maze[i][j + 1] != 'X') {
		// Assume karo recursion bata dega right se raasta milla ya nahi
		bool kyaRightSeRaastaMilla = ratInMaze(maze, sol, i, j + 1, n, m);
		if (kyaRightSeRaastaMilla == true) {
			// Agar right se raasta mill gaya toh problem solved krdo return true
			return true;
		}

		// Yaha aa gaye mtlb right se raasta nhi milla varna return true ho jaata
		// return false nhi krenge kyunki ho skta hai neeche se raasta ho
	}

	// 2. Agar right se nhi hui solve toh down jaana hai i,j cell se and again ask rec hua solve?
	if (i + 1 < n and maze[i + 1][j] != 'X') {
		// Assume karo recursion bata dega down se raasta milla ya nahi
		bool downSeRaastaMilla = ratInMaze(maze, sol, i + 1, j, n, m);
		if (downSeRaastaMilla == true) {
			// Agar down se raasta mill gaya toh problem solved krdo return true
			return true;
		}

	}

	// Agr na right se solve hua na down se solve hua that means i,j cell sol ka part nhi h
	sol[i][j] = 0; // backtracking
	return false;
}


int main() {

	char maze[][5] = {
		"0000",
		"00XX",
		"0000",
		"XX00",
	};

	int sol[10][10] = {0};
	ratInMaze(maze, sol, 0, 0, 4, 4);



	return 0;
}
















