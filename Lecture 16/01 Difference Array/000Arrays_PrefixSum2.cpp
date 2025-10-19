#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> arr = {10, 20, 30, 40, 50};
	int n = arr.size();

	// here, we are computing prefix sums of arr[] and storing them in the arr itself

	// arr[0] stores psum[0]

	for (int i = 1; i < n; i++) {
		// arr[i] = arr[i] + arr[i - 1]; // arr[i-1] stores psum[i-1]
		arr[i] += arr[i - 1];
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}