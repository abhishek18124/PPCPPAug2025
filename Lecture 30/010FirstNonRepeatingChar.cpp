#include<iostream>
#include<queue>

using namespace std;

int main() {

	queue<char> q;
	int freq[26] = {0};

	char ch;

	while (true) {

		cin >> ch;

		if (ch == '.') break;

		freq[ch - 'a']++;
		if (freq[ch - 'a'] == 1) {
			// ch is non-repeating, so track it in the queue
			q.push(ch);
		}

		// what is the 1st non-repeating char. in the stream
		// after reading ch

		while (!q.empty() and freq[q.front() - 'a'] > 1) {
			// whatever is at the front of the queue is no longer non-repeating, so delete it
			q.pop();
		}

		if (q.empty()) {
			cout << -1 << " ";
		} else {
			cout << q.front() << " ";
		}

	}

	return 0;
}