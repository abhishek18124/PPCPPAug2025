#include<iostream>

using namespace std;

void greet() {
	cout << "namaste" << endl;
}

int add(int a, int b) {
	return a + b;
}

bool ascending(int a, int b) {
	return a > b; // return true if a > b otherwise return false
}

int main() {

	cout << (void*)&greet << endl;
	cout << (void*)&add << endl;
	cout << (void*)&ascending << endl;

	// to access address of a function, using & is optional

	cout << (void*)greet << endl;
	cout << (void*)add << endl;
	cout << (void*)ascending << endl;

	void (*gptr)() = &greet; // & is optional
	int (*aptr)(int, int) = &add; // & is optional
	bool (*ascptr)(int, int) = &ascending; // & is optional

	cout << (void*)gptr << endl;
	cout << (void*)aptr << endl;
	cout << (void*)ascptr << endl;

	greet();
	(*gptr)();
	gptr(); // using dereference operator with a fn ptr to call the fn is optional
	(*greet)();

	cout << add(1, 2) << endl;
	cout << (*aptr)(1, 2) << endl;
	cout << aptr(1, 2) << endl;
	cout << (*add)(1, 2) << endl;

	cout << ascending(3, 4) << endl;
	cout << (*ascptr)(3, 4) << endl;
	cout << ascptr(3, 4) << endl;
	cout << (*ascending)(3, 4) << endl;

	return 0;
}