#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1 = "abc";
	string s2 = "adc";

	cout << s1.compare(s2) << endl;

	if (s1 > s2) {
		cout << "yes" << endl;
	} else {
		cout << "no" << endl;
	}

	return 0;
}