#include <iostream>
using namespace std;

void permutation(string ip, string op) {
	// base case
	if (ip.size() == 0) {
		cout << op << endl;
		return;
	}

	for (int i = 0; i < ip.size(); ++i)
	{
		permutation( ip.substr(0, i) + ip.substr(i + 1) , op + ip[i]);
	}
}

int main() {

	string s = "abc";
	string op = "";
	permutation(s, op);
	// s += 'g'; // yaha string s update ho gai
	// cout << s << endl;

	// cout << s + 'h' << endl;
	// cout << s << endl;


	// ith character hatana
	// int i = 2;
	// cout << s.substr(0, i) + s.substr(i + 1) << endl;

	return 0;
}
















