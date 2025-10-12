#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	// time : O(n)
	// space: O(1)

	int serejaScore = 0;
	int dimaScore = 0;

	int i = 0;
	int j = n - 1;

	bool serejasTurn = true;

	while (i <= j) {

		if (serejasTurn) {

			// sereja's turn

			if (v[i] > v[j]) {

				// sereja will pick the ith card

				serejaScore += v[i];
				i++;

			} else {

				// sereje will pick the jth card

				serejaScore += v[j];
				j--;

			}

			serejasTurn = false;

		} else {

			// dima's turn

			if (v[i] > v[j]) {

				// dima will pick the ith card

				dimaScore += v[i];
				i++;

			} else {

				// sereje will pick the jth card

				dimaScore += v[j];
				j--;

			}

			serejasTurn = true;

		}

	}

	cout << serejaScore << " " << dimaScore << endl;

	return 0;
}