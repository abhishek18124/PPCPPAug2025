#include<iostream>

using namespace std;

// time : n/2.const ~ O(n)
// space: O(1)

bool isPalindrome(char str[]) {

	int n = strlen(str);

	int i = 0;
	int j = n - 1;

	while (i < j) {

		if (str[i] != str[j]) {
			// str[] is not a palindrome
			return false;
		} else {
			i++;
			j--;
		}

	}

	// str[] is a palindrome
	return true;

}

int main() {

	char str[] = "racecar";

	isPalindrome(str) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}