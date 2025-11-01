#include<iostream>
#include<string>

using namespace std;

int main() {

	string str = "ababbaab";

	int ans = 0; // to track rudeness
	int cntb = 0;

	// time : O(n)
	// space: O(1)

	int n = str.size();

	for (int i = n - 1; i >= 0; i--) {
		if (str[i] == 'a') {
			ans += cntb;
		} else if (str[i] == 'b') {
			cntb++;
		}
	}

	cout << ans << endl;

	return 0;
}