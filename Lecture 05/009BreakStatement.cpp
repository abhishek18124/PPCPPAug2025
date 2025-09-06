#include<iostream>

using namespace std;

int main() {

	int cnt = 0; // to track the count of non-negative nos.
	int data;

	while (true) {
		cin >> data;
		if (data < 0) {
			break;
		}
		cnt++;
	}

	cout << "count = " << cnt << endl;

	return 0;
}