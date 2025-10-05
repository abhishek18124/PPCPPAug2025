#include<iostream>

using namespace std;

int lowerBound(int arr[], int n, int t) {

	int s = 0;
	int e = n - 1;
	int ans = -1; // to track the index of the 1st occ. of 't' in arr[]

	while (s <= e) {
		int m = (s + e) / 2;
		if (arr[m] == t) {
			ans = m; // we've found the 't' at index 'm', save m and continue the search towards the left of 'm'
			// i.e. reduce the search space from [s, e] to [s, m-1]
			e = m - 1;
		} else {
			if (t > arr[m]) {
				// reduce the search space from [s, e] to [m+1, e]
				s = m + 1;
			} else {
				// t < arr[m]
				// reduce the search space from [s, e] to [s, m-1]
				e = m - 1;
			}
		}
	}

	return ans;

}


int main() {

	int arr[] = {10, 20, 30, 30, 30, 30, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	int t = 30;

	cout << lowerBound(arr, n, t) << endl;

	return 0;
}