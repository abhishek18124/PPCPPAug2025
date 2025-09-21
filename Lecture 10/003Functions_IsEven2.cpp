#include<iostream>

using namespace std;

// bool isEven(int n) {
// 	if (n % 2 == 0) {
// 		return true;
// 	} else {
// 		return false;
// 	}
// }

// bool isEven(int n) {
// 	if (n % 2 == 0) {
// 		return true;
// 	}

// 	return false;
// }

// bool isEven(int n) {
// 	return n % 2 == 0 ? true : false;
// }

bool isEven(int n) {
	return n % 2 == 0;
}

int main() {

	bool ans;

	ans = isEven(4);
	cout << ans << endl;

	cout << isEven(5) << endl;

	// if a fn call returns a value, you can treat that function
	// call like an expression

	if (isEven(7)) {
		cout << "even" << endl;
	} else {
		cout << "odd" << endl;
	}


	if (isEven(6)) {
		cout << "even" << endl;
	} else {
		cout << "odd" << endl;
	}

	return 0;
}