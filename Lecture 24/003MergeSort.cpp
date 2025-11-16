// constraints : n <= 100

#include<iostream>

using namespace std;

void merge(int arr[], int s, int m, int e) {

	// merge the two sorted subarrays arr[s...m] and arr[m+1...e]
	// such that arr[s...e] becomes sorted

	int temp[100];

	int i = s; // to iterate over arr[s...m]
	int j = m + 1; // to iterate over arr[m+1...e]
	int k = s; // to iterate temp[s...e]

	while (i <= m and j <= e) {
		if (arr[i] <= arr[j]) {
			temp[k] = arr[i];
			i++;
			k++;
		} else {
			temp[k] = arr[j];
			j++;
			k++;
		}
	}

	while (i <= m) {
		temp[k] = arr[i];
		i++;
		k++;
	}

	while (j <= e) {
		temp[k] = arr[j];
		j++;
		k++;
	}

	// at this point of time temp[s...e] is sorted

	// now to make sure arr[s...e] is also sorted

	// copy elements of temp[s...e] into arr[s..e]

	for (int i = s; i <= e; i++) {
		arr[i] = temp[i];
	}


}

// time : O(nlogn)
// space: O(n)

void f(int arr[], int s, int e) {

	// base case

	if (s == e) {
		return;
	}

	// recursive case

	// sort the array from index s to index e using the merge sort algorithm

	// 1. divide the array around the mid-point

	int m = s + (e - s) / 2;

	// 2. ask your friend to sort arr[s..m] and arr[m+1...e]

	f(arr, s, m);
	f(arr, m + 1, e);

	// 3. merge the two sorted subarray arr[s...m] and arr[m+1...e]
	// such that arr[s...e] becomes sorted

	merge(arr, s, m, e);

}

int main() {

	int arr[] = {50, 40, 30, 20, 10};
	int n = sizeof(arr) / sizeof(int);

	f(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}