#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int longestPalindrome(const string& str) {

	set<char> s;
	int cnt = 0;

	string leftAns = "";
	string rightAns = "";

	for (char ch : str) {

		if (s.find(ch) == s.end()) {
			s.insert(ch);
		} else {
			s.erase(ch);
			cnt += 2;
			leftAns += ch;
			rightAns += ch;
		}

	}

	reverse(rightAns.begin(), rightAns.end());

	if (!s.empty()) {
		char middleChar = *s.begin();
		cnt++;
		cout << leftAns + string(1, middleChar) + rightAns << endl;
	} else {
		cout << leftAns + rightAns << endl;
	}


	return cnt;

}

int main() {

	string str = "abccccdd";

	cout << longestPalindrome(str) << endl;

	return 0;
}