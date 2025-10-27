#include <iostream>
using namespace std;

// Time: O(logN)
int fastPower(int x, int n) {
	// Kisi ki bhi power 0 times is 1
	if (n == 0) {
		return 1;
	}

	// Recursive case
	// N odd: x * fastPower(x,n/2)* fastPower(x, n/2)
	// N even: fastPower(x,n/2)* fastPower(x, n/2)
	int chotaAns = fastPower(x, n / 2);
	if (n % 2 == 0) { // even hai n
		return chotaAns * chotaAns;
	}
	else { // odd hai n
		return x * chotaAns * chotaAns;
	}
}

int main() {

	cout << fastPower(3, 7) << endl;

	return 0;
}
















