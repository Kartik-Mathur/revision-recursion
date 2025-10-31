#include <iostream>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n) {
	for (int k = 0; k < i; ++k)
	{
		if (board[k][j] == 1) {
			return false;
		}
	}

	int x = i, y = j;
	while (i >= 0 and j < n) {
		if (board[i][j] == 1) {
			return false;
		}
		i--;
		j++;
	}

	i = x;
	j = y;
	while (i >= 0 and j >= 0) {
		if (board[i][j] == 1) {
			return false;
		}
		i--;
		j--;
	}

	// Agar yaha aa gaye mtlb queen yaha rakhna safe hai done...
	return true;
}

bool nQueen(int board[][10], int i, int n) {
	// base case
	if (i == n) {
		// Saari queens place ho gai toh print krdo board ko
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		return false;
	}

	// recursive case
	// ith row ke har column par queen rakh kr dekho ho paa rhi hai saari queens place?
	for (int j = 0; j < n; ++j)
	{
		// Agar kisi bhi i,j par queen rakh kar baaki n-1 queens place ho paai
		// return true kar denge agr place ho pai queen kisi bhi i,j cell par
		if (isSafe(board, i, j, n) == true) {
			// Agar safe hai toh queen rakhdo
			board[i][j] = 1; // iska mtlb i,j cell par ek queen rakhdi

			// ab ask recursion ki baaki n-1 rows mei queen place ho paai ya nahi
			bool kyaBakiQueenPlaceHui = nQueen(board, i + 1, n);
			if (kyaBakiQueenPlaceHui == true) {
				// Agar recursion ne n-1 queens place krdi
				// ek queen toh meine bhi kri hai ith row mei
				return true; // n queens ho gai place toh bas done kaam
			}

			board[i][j] = 0; // agar i,j par queen rakhne ke baad n-1 queens place nhi ho
			// paai that means i,j is not the correct cell to place queen this do backtracking

		}
	}

	// Agar j->[0,n-1], kisi bhi column par ith row ke hum queen place nhi kr paaye
	return false; // is row mei kahi queen rakhna possible nhi ho skta
}

int main() {

	int board[10][10] = {0};
	nQueen(board, 0, 4);


	return 0;
}
















