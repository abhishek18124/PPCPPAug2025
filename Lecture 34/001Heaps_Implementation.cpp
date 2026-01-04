/*

	Implementation of the heap/priority_queue data structure.

*/

#include<iostream>
#include<vector>

using namespace std;

class minHeap {

	vector<int> v; // internal repr of min heap

	void heapify(int i) { // logn // [HW] try to impl. iteratively

		// fix the minHeap prop. at the ith index

		int minIdx = i; // assume value at index i is the smallest

		int leftIdx = 2 * i + 1;

		if (leftIdx < v.size() and v[leftIdx] < v[minIdx]) {
			minIdx = leftIdx;
		}

		int rightIdx = 2 * i + 2;

		if (rightIdx < v.size() and v[rightIdx] < v[minIdx]) {
			minIdx = rightIdx;
		}

		if (minIdx != i) {

			// minHeap prop. was defintely not working at index i

			swap(v[i], v[minIdx]);
			heapify(minIdx);

		}

	}

public:

	// time : O(logn)

	void push(int val) {

		v.push_back(val);
		int childIdx = v.size() - 1;
		// int parentIdx = childIdx % 2 == 1 ? childIdx / 2 : (childIdx / 2) - 1;
		int parentIdx = (childIdx - 1) / 2;

		while (childIdx != 0 and v[childIdx] < v[parentIdx]) {
			swap(v[childIdx], v[parentIdx]);
			childIdx = parentIdx;
			// parentIdx = childIdx % 2 == 1 ? childIdx / 2 : (childIdx / 2) - 1;
			parentIdx = (childIdx - 1) / 2;
		}

	}

	// time : O(logn)

	void pop() {
		swap(v[0], v[v.size() - 1]); // const
		v.pop_back(); // const
		heapify(0); // fix the min heap prop. at the root node i.e. index 0 // logn
	}

	// time : O(1)

	int top() {
		return v[0];
	}

	// time : O(1)

	int size() {
		return v.size();
	}

	// time : O(1)

	bool empty() {
		return v.empty();
	}

};

int main() {

	minHeap m;

	m.push(9);
	m.push(7);
	m.push(8);
	m.push(5);
	m.push(4);
	m.push(6);
	m.push(3);
	m.push(2);
	m.push(1);

	cout << m.size() << endl;

	while (!m.empty()) {
		cout << m.top() << " ";
		m.pop();
	}

	cout << endl;

	cout << m.size() << endl;

	return 0;
}



