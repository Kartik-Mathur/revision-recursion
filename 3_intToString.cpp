#include <iostream>
using namespace std;

string keys[10] = {
	"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};

void intToString(int n) {
	// base case
	if (n == 0) {
		return;
	}

	// recursive case
	// Ek last digit ka kaam hum kr dete hai
	int ld = n % 10; // yeh humesha [0,9] ke beech mei hi hoga
	// cout << keys[ld] << " "; // us digit ke corresponding string aise mill jaegi

	// Baaki digits ko string mei convert krne ko recursion ko bol dete hai...
	intToString(n / 10);
	cout << keys[ld] << " "; // us digit ke corresponding string aise mill jaegi
}

int main() {

	int n = 2048;

	intToString(n);


	return 0;
}
















