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

	bool flag = false; // assume t is not present in arr[]

	for (i = 0; i < n; i++) {
		if (arr[i] == t) {
			cout << i << endl;
			flag = true; // assumption was wrong
		}
	}

	if (flag == false) { // assumption was correct
		cout << -1 << endl;
	}


	return 0;
}