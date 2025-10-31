#include <iostream>
using namespace std;

void Perumtations(char *a, int i) {
	if (a[i] == '\0') {
		cout << a << endl;
		return;
	}

	// Recursive case
	// Ek ek krke ith position par saare characters lekar aane hai hume
	for (int j = i; a[j] != '\0'; ++j)
	{
		swap(a[i], a[j]);
		Perumtations(a, i + 1);
		swap(a[i], a[j]); // backtracking
	}
}


int main() {

	char a[] = "abc";
	Perumtations(a, 0);

	return 0;
}
















