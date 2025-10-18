#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> a = {10, 30, 50, 70}; // 0 to n-1
	vector<int> b = {20, 40, 60}; // 0 to m-1

	int n = a.size(); // 4
	int m = b.size(); // 3

	vector<int> c(n + m);

	int i = 0; // to iterate over a[]
	int j = 0; // to iterate over b[]
	int k = 0; // to iterate over c[]

	// time : (n+m).const ~ O(n+m)
	// space: O(1) excluding the output i.e. c[]

	while (i < n and j < m) {
		if (a[i] < b[j]) {
			c[k] = a[i];
			i++;
			k++;
		} else {
			c[k] = b[j];
			j++;
			k++;
		}
	}

	while (j < m) { // if this loop runs, it means a[] was exhausted so we are copying remaining elements of b[] into c[]
		c[k] = b[j];
		j++;
		k++;
	}

	while (i < n) { // if this loop runs, it means b[] was exhausted so we are copying remaining elements of a[] into c[]
		c[k] = a[i];
		i++;
		k++;
	}

	for (int x : c) {
		cout << x << " ";
	}

	cout << endl;

	for (int i = 0; i < c.size(); i++) {
		cout << c[i] << " ";
	}

	cout << endl;

	return 0;
}

