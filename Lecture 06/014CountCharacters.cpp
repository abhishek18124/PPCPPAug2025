#include<iostream>

using namespace std;

int main() {

	int cnt = 0; // to track the no. of characters

	char ch;

	while (true) {

		// cin >> ch; // cin >> skips / ignores whitespaces

		ch = cin.get(); // cin.get() can be used to read whitespaces

		if (ch == '$') {
			break;
		}

		cnt++;

	}

	cout << "cnt = " << cnt << endl;

	return 0;
}