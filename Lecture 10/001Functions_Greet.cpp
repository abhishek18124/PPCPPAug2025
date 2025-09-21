#include<iostream>

using namespace std;

void greet() {
	cout << "hello world" << endl;
	return; // optional
}

int main() {

	cout << "I am inside main(), before greet()" << endl;

	greet(); // function call or function invocation

	cout << "I am inside main(), after greet()" << endl;

	return 0;
}