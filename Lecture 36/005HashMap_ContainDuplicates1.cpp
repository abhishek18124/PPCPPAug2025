#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<set>

using namespace std;

// time : O(nlogn) when using a map<>
// time : n * on avg const ~ on avg. O(n) but worst case O(n^2) when using unordered_map
// space: O(n) due to map<> or unordered_map<>

bool isDuplicatePresentUsingMap(const vector<int>& v) {

	map<int, int> freqMap;

	for (int x : v) {
		freqMap[x]++;
		if (freqMap[x] > 1) {
			// we've found a duplicate
			return true;
		}
	}

	return false;

}

bool isDuplicatePresentUsingSet(const vector<int>& v) {

	set<int> s;

	for (int x : v) {
		if (s.find(x) == s.end()) {
			s.insert(x);
		} else {
			// x is already present which means you've found a duplicate
			return true;
		}
	}

	return false;

}

int main() {

	vector<int> v = {1, 2, 4, 4};

	isDuplicatePresentUsingMap(v) ? cout << "duplicate found" << endl :
	                                     cout << "duplicate not found" << endl;

	isDuplicatePresentUsingSet(v) ? cout << "duplicate found" << endl :
	                                     cout << "duplicate not found" << endl;

	return 0;
}