#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int main() {

	string str;
	// cin >> str; // cin >> stop reads string as soon as it encounters a non-leading whitespace, leading whitespacs are ignored
	// getline(cin, str); // we stop reading at '\n' which is the default delimiting character
	getline(cin >> ws, str); // cin >> ws helps ignores leading whitespaces
	cout << str << endl;

	return 0;
}