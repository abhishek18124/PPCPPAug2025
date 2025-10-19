/*

e.g.

input
5 3
4 1 5 2 3
0 2 5
2 3 2
3 4 7

output
9 6 12 11 10

*/

#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n, q;
	cin >> n >> q;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> diff(n + 1, 0);

	while (q--) { // q.const
		int l, r, x;
		cin >> l >> r >> x;
		diff[l] += x;
		diff[r + 1] -= x;
	}

	// for (int i = 0; i <= n; i++) {
	// 	cout << diff[i] << " ";
	// }

	// cout << endl;

	for (int i = 1; i <= n; i++) { // n.const
		diff[i] += diff[i - 1];
	}

	// for (int i = 0; i <= n; i++) {
	// 	cout << diff[i] << " ";
	// }

	// cout << endl;

	for (int i = 0; i < n; i++) { // n.const
		arr[i] += diff[i];
	}

	// time : O(q+2n)
	// space: O(n) due to diff[]

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}