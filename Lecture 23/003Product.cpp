#include<iostream>

using namespace std;

int f(int x, int y) {

	// base case

	if (y == 0) {

		// find out f(x, 0) i.e. x * 0

		return 0;

	}

	// recursive case

	// f(x, y) = find out x * y

	// 1. ask your friend to find out x * (y-1)

	int A = f(x, y - 1);

	return x + A;

}

int main() {

	int x = 5;
	int y = 10;

	cout << f(x, y) << endl;

	return 0;
}