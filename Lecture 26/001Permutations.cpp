/*

Given a string (sequence of characters) of length n, generate all of its permutations.

Example

	Input : inp[] = "abc"
	Output: ["abc", "acb", "bac", "bca", "cba", "cab"]

*/

#include<iostream>
#include<cstring>

using namespace std;

void f(char inp[], int n, int i) {

	// base case

	if (inp[i] == '\0') { // i == n // you've managed to build a permutation
		cout << inp << endl;
		return;
	}

	// recursive case

	// f(i) = take decisions for remaining slots i to n-1

	// decide for the ith index

	for (int j = i; j <= n - 1; j++) {

		swap(inp[i], inp[j]);
		f(inp, n, i + 1);
		swap(inp[i], inp[j]); // backtracking

	}

}

int main() {

	char inp[] = "aabc";
	int n = strlen(inp);

	f(inp, n, 0);

	return 0;
}
