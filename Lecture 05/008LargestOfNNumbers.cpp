#include<iostream>
#include<climits>

using namespace std;

int main() {

	int n;
	cin >> n;

	int maxsofar = INT_MIN; // to track the "largest so far"

	int i = 1;

	while (i <= n) {
		int x;
		cin >> x;
		if (x > maxsofar) {
			maxsofar = x;
		}
		i = i + 1;
	}

	cout << maxsofar << endl;

	return 0;
}