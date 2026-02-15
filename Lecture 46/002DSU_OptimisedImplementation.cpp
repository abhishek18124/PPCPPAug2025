/*

optimising union and find operations using

* union by rank
* path compression

*/

#include<iostream>
#include<vector>

using namespace std;

#include<iostream>
#include<vector>

using namespace std;

class disjointSet {

	vector<int> parMap;
	vector<int> rankMap;

public:

	disjointSet(int n) {
		parMap.resize(n + 1);
		rankMap.resize(n + 1);
	}

	void createSet(int x) {
		parMap[x] = x;
		rankMap[x] = 0;
	}

	int findSet(int x) {
		if (parMap[x] == x) {
			return x;
		}

		return parMap[x] = findSet(parMap[x]); // path compression
	}

	void unionSet(int x, int y) {
		int lx = findSet(x);
		int ly = findSet(y);

		if (lx != ly) {

			if (rankMap[lx] == rankMap[ly]) {
				rankMap[lx]++;
			}

			if (rankMap[lx] > rankMap[ly]) {
				parMap[ly] = lx;
			} else {
				// rankMap[ly] > rankMap[lx]
				parMap[lx] = ly;
			}

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