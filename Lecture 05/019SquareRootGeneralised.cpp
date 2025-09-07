#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int p;
	cin >> p;

	double ans = 0;

	while (ans * ans <= n) {
		ans = ans + 1;
	}

	ans = ans - 1;

	double inc = 0.1;

	for (int i = 1; i <= p; i++) {

		while (ans * ans <= n) {
			ans = ans + inc;
		}

		ans = ans - inc;
		inc = inc / 10;

	}

	cout << ans << endl;

	return 0;
}