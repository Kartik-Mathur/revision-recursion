#include <iostream>
using namespace std;
// Main is to sort n elements using bubble sort algorithm
void bubbleSort(int *a, int n, int i) {
	// base case
	// Jab n-1 elements uski sahi jagah pahunch gaye that means array is sorted stop
	if (i == n - 1) {
		return;
	}

	// recursive case
	// Ek element ko sahi jagah hum rakh dete hai, using bubble sort algo
	for (int j = 0; j < n - 1 - i; ++j)
	{
		if (a[j] > a[j + 1]) {
			swap(a[j], a[j + 1]);
		}
	}

	// n-1 elements ko sahi jagah rakhne ke liye recursion ko bol denge
	bubbleSort(a, n, i + 1);
}

int main() {

	int a[] = {4, 3, 5, 1, 2};
	int n = sizeof(a) / sizeof(int);

	bubbleSort(a, n, 0);
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;


	return 0;
}
















