#include<iostream>

using namespace std;

int main() {

	char str[] = {'a', 'b', 'c', 'd', 'e', '\0'};
	cout << str << endl;

	for (int i = 0; str[i] != '\0'; i++) {
		cout << str[i] << endl;
	}

	char str2[] = "hello";

	// when you init a char array with a string literal
	// '\0' is added automatically

	cout << str2 << endl;

	return 0;
}