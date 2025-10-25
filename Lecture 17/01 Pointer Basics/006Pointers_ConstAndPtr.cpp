#include<iostream>

using namespace std;

int main() {

	int x = 10;
	int* ptr1 = &x; // ptr to int
	const int* ptr2 = &x; // ptr to const-int
	int* const ptr3 = &x; // const ptr to int
	const int* const ptr4 = &x; // const ptr to const-int

	return 0;
}