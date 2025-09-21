#include<iostream>

using namespace std;

void incr(int& ref) { // here, we are passing by ref so changes done to parameter will be reflected in the argument
	cout << ref << endl; // 0
	ref++;
	cout << ref << endl; // 1
}

int main() {

	int a = 0;

	cout << a << endl; // 0

	incr(a);

	cout << a << endl; // 1

	return 0;

}