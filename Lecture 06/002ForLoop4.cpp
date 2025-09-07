#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	for (int i = 1, j = n; i < j; i++, j--) {
		cout << i << " " << j << endl;
	}

	cout << endl;

	int i = 1;
	int j = n;

	while (i < j) {
		cout << i << " " << j << endl;
		i++;
		j--;
	}

	return 0;
}