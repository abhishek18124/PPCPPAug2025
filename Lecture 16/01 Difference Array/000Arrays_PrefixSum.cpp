#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> arr = {10, 20, 30, 40, 50};
	int n = arr.size();

	vector<int> psum(n);

	// psum[0] stores sum of the prefix ending at the 0th index
	// psum[1] stores sum of the prefix ending at the 1st index
	// psum[2] stores sum of the prefix ending at the 2nd index
	// ...
	// psum[i] stores sum of the prefix ending at the ith index

	psum[0] = arr[0];

	// psum[1] = psum[0] + arr[1];
	// psum[2] = psum[1] + arr[2];
	// psum[3] = psum[2] + arr[3];
	// ...
	// psum[i] = psum[i-1] + arr[i];


	for (int i = 1; i < n; i++) {
		psum[i] = psum[i - 1] + arr[i];
	}

	for (int i = 0; i < n; i++) {
		cout << psum[i] << " ";
	}

	cout << endl;

	return 0;
}