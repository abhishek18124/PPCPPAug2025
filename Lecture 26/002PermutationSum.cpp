#include<iostream>
#include<vector>

using namespace std;

void generatePermutations(int t, const vector<int>& c, vector<int>& out) {

	// base case

	if (t == 0) { // you've managed to build a valid permuation of c[]
		for (int y : out) {
			cout << y << " ";
		}
		cout << endl;
		return;
	}

	// recursion case

	// generate permutations of 'c' that sums up to 't' or choose candidates that sum up to 't'

	// decide the next candidate

	for (int x : c) {
		if (x <= t) {
			out.push_back(x);
			generatePermutations(t - x, c, out);
			out.pop_back(); // backtracking
		}
	}

}

int main() {

	vector<int> c = {2, 3, 5, 7};
	int t = 7;

	vector<int> out; // to track a sigle permutation of c[] that sums up to 't'

	generatePermutations(t, c, out);

	return 0;
}