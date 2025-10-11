#include<iostream>
#include<vector>

using namespace std;

void f(const vector<int>& v) { // todo ...

	for (int i = 0; i < v.size(); i++) {
		// cout << v[i] << " ";
		v[i]++;
	}

	cout << endl;

}

int main() {

	vector<int> v = {0, 1, 2, 3, 4};

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	f(v);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;


	return 0;
}