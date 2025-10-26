#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {

	int arr[] = {50, 40, 40, 30, 30, 30, 20, 10, 10};
	int n = sizeof(arr) / sizeof(int);

	// 1. finding the minimum value in a sequence

	cout << *max_element(arr, arr + n) << endl;

	// 2. finding the maximum value in a sequence

	cout << *min_element(arr, arr + n) << endl;

	vector<int> v = {50, 20, -10, 100, 50};

	cout << *max_element(v.begin(), v.end()) << endl;
	cout << *min_element(v.begin(), v.end()) << endl;



	return 0;
}
