#include<iostream>
#include<string>

using namespace std;

bool isGoodString(const string& str) {

	for (char ch : str) {
		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
			// str is not good
			return false;
		}
	}

	// str is good
	return true;

}

// time : O(n^3)

int longestGoodSubstring(const string& str) {
	int n = str.size();
	int maxSofar = 0; // INT_MIN
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			string subString = str.substr(i, j - i + 1);
			if (isGoodString(subString)) {
				maxSofar = max(maxSofar, j - i + 1);
			}
		}
	}
	return maxSofar;
}

int main() {

	string str = "cbaeicdeiou";

	cout << longestGoodSubstring(str) << endl;

	return 0;
}