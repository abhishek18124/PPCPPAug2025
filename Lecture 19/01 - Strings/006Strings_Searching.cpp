#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "abcdabcdabcd";

	cout << s.find("cda") << endl;
	cout << s.rfind("cda") << endl;
	cout << s.find("xyz") << endl;

	cout << string::npos << endl;
	cout << (string::npos == -1) << endl; // [HW] why is this true

	return 0;
}