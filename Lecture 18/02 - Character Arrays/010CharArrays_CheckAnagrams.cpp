#include<iostream>

using namespace std;

// time : n + n + 26 = 2n + 26 assuming len of s1 is equal len of s2 = n
// space: 26 + 26 for f1[] and f2[] ~ const

bool isAnagram(char s1[], char s2[]) {

	int f1[26] = {0};
	for (int i = 0; s1[i] != '\0'; i++) {
		char ch = s1[i];
		int idx = ch - 'a';
		f1[idx]++;
	}

	// for (int i = 0; i < 26; i++) {
	// 	cout << f1[i] << " ";
	// }

	// cout << endl;

	int f2[26] = {0};
	for (int i = 0; s2[i] != '\0'; i++) {
		f2[s2[i] - 'a']++;
	}

	// for (int i = 0; i < 26; i++) {
	// 	cout << f2[i] << " ";
	// }

	// cout << endl;

	for (int i = 0; i < 26; i++) {
		if (f1[i] != f2[i]) {
			return false; // s1 & s2 are not anagrams
		}
	}

	return true; // s1 & s2 are anagrams

}

int main() {

	char s1[] = "state";
	char s2[] = "taste";

	isAnagram(s1, s2) ? cout << "anagram" << endl : cout << "not anagram" << endl;

	return 0;
}