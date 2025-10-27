#include <iostream>
using namespace std;

// Main : n disks ko src se destination par lekar jaana
void toh(int n, char src, char helper, char des) {
	// koi disk nhi hai toh vapis jaao not possible to play game...
	if (n == 0) {
		return;
	}

	// Recursive case
	// 1. n-1 disk ko src se helper pr move kardo
	toh(n - 1, src, des, helper);
	cout << "Take disk " << n << " from " << src << " to " << des << endl;
	toh(n - 1, helper, src , des);
}

int main() {

	int n = 3;
	toh(n, 'A', 'B', 'C');

	return 0;
}
















