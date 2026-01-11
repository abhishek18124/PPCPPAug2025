#include<iostream>
#include<vector>
#include<set>

using namespace std;

int longestPalindrome(const string& str) {

	set<char> s;
	int cnt = 0;

	for (char ch : str) {

		if (s.find(ch) == s.end()) {
			s.insert(ch);
		} else {
			s.erase(ch);
			cnt += 2;
		}

	}

	if (!s.empty()) cnt++;

	return cnt;

}

int main() {

	string str = "abccccdd";

	cout << longestPalindrome(str) << endl;

	return 0;
}