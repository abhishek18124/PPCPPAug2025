#include<iostream>

using namespace std;

int main() {

	int* ptr = new int;

	*ptr = 20;

	cout << *ptr << endl;

	delete ptr;

	double* dptr =  new double;

	*dptr = 3.14;

	cout << *dptr << endl;

	delete dptr;

	char* chptr = new char;

	*chptr = 'A';

	cout << *chptr << endl;

	delete chptr;

	return 0;
}