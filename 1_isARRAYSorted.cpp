#include <iostream>
using namespace std;

// Way-1
bool isSorted(int *a, int n) {
	// base case
	if (n == 0 or n == 1) {
		return true; // Array mei kuch bhi nhi hai toh by default usse sorted hi kahenge...
	}

	// recursive case
	// isSorted(a+1,n-1) : Yeh assumption hai ki chota array sorted hai ya nhi hai rec bataega
	// a[0]<a[1] : Ek bucket ka kaam hum kar rhey hai
	if (a[0] <= a[1] and isSorted(a + 1, n - 1) == true) {
		return true;
	}

	// Upr if ki condition fail hui mtlb array sorted nhi ho skta
	return false;
}

// Way-2
bool isSorted2(int *a, int n, int i) {
	if (i == n - 1) {
		// agar ek hi element hai toh yeh condition true hogi, that means array sorted hoga
		return true;
	}

	// Recursive case
	// a[i]<=a[i+1]: Ek index ko mei check kr lete hoon
	// isSorted2(a,n,i+1): Baaki ke remaining indexes ka kaam hum recursion se puch lete hai
	if (a[i] <= a[i + 1] and isSorted2(a, n, i + 1) == true) {
		// Iska matlab upr ki dono conditions true hai that means entire array is sorted
		return true;
	}

	// Iska mtlb bada array sorted nhi ho skta thus return false
	return false;
}

// Way-3: Last index ka kaam check krenge rather than 0th index
bool isSorted3(int *a, int n) {
	if (n == 1 or n == 0) {
		return true;
	}

	// Recursive case
	// a[n-1]>=a[n-2] : Ek last wala element numne check kar diya
	// isSorted3(a,n-1): n-1 elements are sorted or not, recursion ko bola tu bata
	if (a[n - 1] >= a[n - 2] and isSorted3(a, n - 1) == true) {
		return true;
	}

	return false;
}


int main() {

	int a[] = {1, 2, 3, 4, 5};
	int n = sizeof(a) / sizeof(int);

	if (isSorted3(a, n) == true) {
		cout << "Array sorted\n";
	}
	else {
		cout << "Array not sorted\n";
	}

	return 0;
}



















