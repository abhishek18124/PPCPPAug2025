#include<iostream>

using namespace std;

// time : O(n^3)
// explanation : we've ~ n^2 subarrays, to print each
// subarray in the worst case we spend linear time
// to overall our algorithsm takes cubic time

void generateSubarrays(int arr[], int n) {

	for (int i = 0; i < n; i++) {

		for (int j = i; j < n; j++) {

			// generate the subarray that
			// starts at the ith index
			// and ends at the jth index

			for (int k = i; k <= j; k++) {
				cout << arr[k] << " ";
			}

			cout << endl;

		}

		cout << endl;

	}

}

int main() {

	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	generateSubarrays(arr, n);

	return 0;
}