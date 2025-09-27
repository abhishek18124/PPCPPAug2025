#include<iostream>

using namespace std;

void modify(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		arr[i]++;
	}
}

int main() {

	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl; // 10 20 30 40 50

	modify(arr, n); // in C++, arr[] are by default passed by reference

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl; // 11 21 31 41 51

	return 0;
}