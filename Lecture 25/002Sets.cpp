/*

	https://cplusplus.com/reference/set/set/?kw=set
	https://cplusplus.com/reference/set/multiset/?kw=multiset

	> insert/erase/find is logarithmic i.e. O(logn)
	> values are inserted in the sorted order
	> set contains only distinct values
	> multiset allows duplicate values

*/

#include<iostream>
#include<set>

using namespace std;

int main() {

	set<int> s;

	cout << "size:  " << s.size() << endl;

	s.insert(5);
	s.insert(4);
	s.insert(3);
	s.insert(2);
	s.insert(1);
	s.insert(1); // nothing will happen as 1 is already present

	cout << "size : " << s.size() << endl; // 5

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	s.erase(5); // 5 will be deleted from the set<>

	cout << "size : " << s.size() << endl; // 4

	s.erase(10); // since 10 is not present, nothing will happen

	for (auto it = s.begin(), end = s.end(); it != end; it++) {
		cout << *it << " ";
	}

	cout << endl;

	for (auto x : s) {
		cout << x << " ";
	}

	cout << endl;

	s.erase(s.begin());

	cout << "size = " << s.size() << endl;

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	auto it = s.begin();

	it++;

	s.erase(it);

	cout << "size = " << s.size() << endl;

	for (auto x : s) {
		cout << x << " ";
	}

	cout << endl;

	if (s.find(3) != s.end()) {
		cout << "3 is present" << endl;
	} else {
		cout << "3 is absent" << endl;
	}

	if (s.find(4) != s.end()) {
		cout << "4 is present" << endl;
	} else {
		cout << "4 is absent" << endl;
	}

	s.erase(s.find(4));

	if (s.find(4) != s.end()) {
		cout << "4 is present" << endl;
	} else {
		cout << "4 is absent" << endl;
	}

	// s.erase(s.find(4)); // error since 4 is not present, find() return s.end()

	if (s.count(5)) {
		cout << "5 is present" << endl;
	} else {
		cout << "5 is absent" << endl;
	}

	if (s.count(2)) {
		cout << "2 is present" << endl;
	} else {
		cout << "2 is absent" << endl;
	}

	s.empty() ? cout << "set<> is empty" << endl : cout << "set<> is not empty" << endl;

	s.clear();

	cout << "size : " << s.size() << endl;

	s.empty() ? cout << "set<> is empty" << endl : cout << "set<> is not empty" << endl;

	return 0;
}