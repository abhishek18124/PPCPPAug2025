#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	// 1. creating a vector using initialiser list

	vector<int> v = {1, 0, 2, 4, 3};

	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	// 2. reversing a vector

	// todo ...

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	// 3. sorting a vector in the increasing order

	// todo ...

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	// 4. sorting a vector in the decreasing order

	// todo ...

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}