#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1 = "abc";
	string s2 = "def";
	// s1 = s1 + s2;
	s1.append(s2);

	cout << s1 << endl;

	string s = "abc";
	s.push_back('d');
	cout << s << endl;
	s.pop_back();
	cout << s << endl;

	return 0;
}