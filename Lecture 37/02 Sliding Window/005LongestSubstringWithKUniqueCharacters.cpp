#include<iostream>
#include<unordered_map>

using namespace std;

int main() {

	string s = "aabacbebebe";
	int n = s.size();
	int k = 3;

	int i = 0; // to store the start of the window
	int j = 0; // to store the end of the windw

	int maxLen = 0; // to track the length of the longest substring
	// i.e. window that contain k unique characters

	int uniqCnt = 0; // to keep track of no. of unique characters in the window

	unordered_map<char, int> freqMap; // to store a  mapping  between characters
	// present in a window & their frequencies

	// time : O(n) assuming map<> operations are const
	// space: O(size of freqMap) ~ O(26) ~ const

	while (j < n) {

		// expand the window

		freqMap[s[j]]++;
		if (freqMap[s[j]] == 1) {
			uniqCnt++;
		}

		// check for the violation of the window property

		if (uniqCnt > k) {

			// window prop. is violated

			// start shrinking

			while (uniqCnt > k) {
				freqMap[s[i]]--;
				if (freqMap[s[i]] == 0) {
					uniqCnt--;
				}
				i++;
			}

		}

		// check for the validity of the window, and update the answer

		if (uniqCnt == k) {
			// found a valid window, track its length
			maxLen = max(maxLen, j - i + 1);

		}

		// continue expansion of the window
		j++;
	}

	cout << maxLen << endl;

	return 0;
}