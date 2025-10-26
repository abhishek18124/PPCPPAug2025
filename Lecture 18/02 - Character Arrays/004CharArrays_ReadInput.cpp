// n <= 100

#include<iostream>

using namespace std;

int main() {

	char str[101]; // based on constraints

	// cin >> str; // cin >> stops reading as soon as it encounters a non-leading whitespace // leading whitespaces are ignored
	// cout << str << endl;

	cin.getline(str, 5, '$'); // stops reading as soon as it encounters a $ of 5B (incl. '\0') is read

	cout << str << endl;

	return 0;
}