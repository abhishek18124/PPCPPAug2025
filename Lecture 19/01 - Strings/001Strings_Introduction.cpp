#include<iostream>
#include<string>

using namespace std;

int main() {

	string str1 = "coding blocks";

	cout << str1 << endl;
	cout << str1.size() << endl;

	for (int i = 0; str1[i] != '\0'; i++) {
		cout << str1[i] << " ";
	}

	cout << endl;


	for (int i = 0; i < str1.size(); i++) {
		cout << str1[i] << " ";
	}

	cout << endl;

	for (char ch : str1) {
		cout << ch << " ";
	}

	cout << endl;

	return 0;
}