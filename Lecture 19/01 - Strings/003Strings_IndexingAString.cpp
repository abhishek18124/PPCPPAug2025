#include<iostream>
#include<string>

using namespace std;

int main() {

	string str = "coding";

	cout << str[0] << endl;
	cout << str.front() << endl;

	cout << str[str.size() - 1] << endl;
	cout << str.back() << endl;

	return 0;
}