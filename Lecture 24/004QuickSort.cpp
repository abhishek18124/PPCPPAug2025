// constraints : n <= 100

#include<iostream>

using namespace std;

int parition(int arr[], int s, int e) {
	int pivot = arr[e];
	int i = s; // point to the slow where the next element < pivot goes
	int j = s;

	while (j < e) {
		if (arr[j] < pivot) {
			// put arr[j] in the left partition
			swap(arr[i], arr[j]);
			i++;
			j++;
		} else {
			// put arr[j] in the right parition
			j++;
		}
	}

	swap(arr[i], arr[e]);

	// arr[s...i-1] : left partition (values < pivot)
	// index i : pivot
	// arr[i+1...e] : right partition (values > pivot)

	return i;
}

void quickSort(int arr[], int s, int e) {

	// base case

	if (s > e) { // mandatory
		return;
	}

	if (s == e) { // optional
		return;
	}

	// recursive case

	int pidx = parition(arr, s, e);
	quickSort(arr, s, pidx - 1);
	quickSort(arr, pidx + 1, e);

}

int main() {

	int arr[] = {60, 50, 20, 10, 40, 30};
	int n = sizeof(arr) / sizeof(int);

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}