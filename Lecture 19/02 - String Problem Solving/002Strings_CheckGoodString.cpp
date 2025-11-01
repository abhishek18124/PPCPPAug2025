#include<iostream>
#include<string>

using namespace std;

// time : O(n)

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

int main() {

	string str = "uoxea";

	if (isGoodString(str)) {
		cout << "good string" << endl;
	} else {
		cout << "not good string" << endl;
	}

	return 0;
}