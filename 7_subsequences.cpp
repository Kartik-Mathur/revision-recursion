#include <iostream>
using namespace std;

void subsequences(char *ip, int i, char *op, int j) {
	// base case
	if (ip[i] == '\0') {
		op[j] = '\0';
		cout << op << endl;
		return;
	}
	// recursive case
	// 1. Exclude ith character ko
	subsequences(ip, i + 1, op, j);
	// 2. Include ith character in op[]
	op[j] = ip[i];
	subsequences(ip, i + 1, op, j + 1);
}

// 1. Kal 7 AM
// 2. Friday 7 AM
// 3. Tueday 6 PM
int main() {

	char ip[] = "abc";
	char op[100];
	subsequences(ip, 0, op, 0);


	return 0;
}
















