#include<iostream>
#include<vector>

using namespace std;

class disjointSet {

	vector<int> parMap;

public:

	disjointSet(int n) {
		parMap.resize(n + 1);
	}

	void createSet(int x) {
		parMap[x] = x;
	}

	int findSet(int x) {
		if (parMap[x] == x) {
			return x;
		}

		return findSet(parMap[x]);
	}

	void unionSet(int x, int y) {
		int lx = findSet(x);
		int ly = findSet(y);

		if (lx != ly) {
			parMap[ly] = lx;  // lx is the new leader of the merged set
			// parMap[lx] = ly; // ly is the new leader of the merged set
		}
	}

};

int main() {

	disjointSet ds(4);

	ds.createSet(1);
	ds.createSet(2);
	ds.createSet(3);
	ds.createSet(4);

	cout << ds.findSet(1) << endl;
	cout << ds.findSet(2) << endl;
	cout << ds.findSet(3) << endl;
	cout << ds.findSet(4) << endl << endl;

	ds.unionSet(2, 3);

	cout << ds.findSet(2) << endl;
	cout << ds.findSet(3) << endl << endl;

	ds.unionSet(1, 4);

	cout << ds.findSet(1) << endl;
	cout << ds.findSet(4) << endl << endl;

	ds.unionSet(2, 4);

	cout << ds.findSet(1) << endl;
	cout << ds.findSet(2) << endl;
	cout << ds.findSet(3) << endl;
	cout << ds.findSet(4) << endl << endl;


	return 0;

}