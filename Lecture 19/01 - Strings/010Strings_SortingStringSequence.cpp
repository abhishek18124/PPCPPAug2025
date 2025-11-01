#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

// return true if you want a to be ordered before b
// otherwise return false

bool lenCmp(string a, string b) {
	if (a.size() < b.size()) {
		// since we are sorting input array by length
		// in the inc. order therefore when length of
		// a is < length of b we want a to be ordered
		// before hence we are returning true
		return true;
	} else {
		return false;
	}

	// return a.size() < b.size();
}

int main() {

	vector<string> names;

	names.push_back("yash");
	names.push_back("ridhi");
	names.push_back("prabhdeep");
	names.push_back("samarth");
	names.push_back("pranavee");
	names.push_back("sid");
	names.push_back("om");
	names.push_back("akshay");

	for (string name : names) {
		cout << name << endl;
	}

	cout << endl << endl;

	sort(names.begin(), names.end()); // by default vector<string> is sorted in lexicographically inc. order

	for (string name : names) {
		cout << name << endl;
	}

	cout << endl;

	sort(names.begin(), names.end(), greater<string>()); // by default vector<string> is sorted in lexicographically inc. order

	for (string name : names) {
		cout << name << endl;
	}

	cout << endl;

	sort(names.begin(), names.end(), lenCmp);

	for (string name : names) {
		cout << name << endl;
	}

	cout << endl;

	return 0;
}