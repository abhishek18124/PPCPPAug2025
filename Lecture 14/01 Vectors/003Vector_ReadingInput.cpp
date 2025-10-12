#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v(n); // creates a vector<> of size n initialised with zero

	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}