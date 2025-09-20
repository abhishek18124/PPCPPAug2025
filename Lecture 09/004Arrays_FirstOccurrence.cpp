// n <= 100

#include<iostream>

using namespace std;

int main() {

	int arr[100]; // based on constraints

	int n;
	cin >> n;

	int t;
	cin >> t;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// time : O(n)

	int i;

	for (i = 0; i < n; i++) {
		if (arr[i] == t) {
			cout << i << endl;
			break;
		}
	}

	if (i == n) {
		cout << -1 << endl;
	}

	return 0;
}