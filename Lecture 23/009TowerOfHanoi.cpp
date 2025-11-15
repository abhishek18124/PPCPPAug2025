#include<iostream>

using namespace std;

void f(int n, char src, char dst, char hlp) {

	// base case

	if (n == 0) {
		return; // mandatory return statement
	}

	// recurisve case

	// move n disks from src i.e. A to dst i.e. C using hlp i.e. B

	// 1. ask your friend to move n-1 disks from src i.e. A to hlp i.e. B using dst i.e. C

	f(n - 1, src, hlp, dst);

	// 2. move largest disk from src i.e. A to dst i.e. C

	cout << "move disk from " << src << " to " << dst << endl;

	// 3. ask your friend to move n-1 disks from hlp i.e. B to dst i.e. C using src i.e. A

	f(n - 1, hlp, dst, src);

}

int main() {

	int n = 3;

	f(n, 'A', 'C', 'B');

	return 0;
}