/*

	STL implementation of the min_heap data structure with custom comparator.


*/

#include<iostream>
#include<queue>

using namespace std;

class customer {

public:

	string name;
	int age;
	double balance;

	customer(string name, int age, double balance) {
		this->name = name;
		this->age = age;
		this->balance = balance;
	}

};

class ageComparator {

public:

	// return false if you want a to be given more priority than b
	// otherwise return true

	bool operator()(customer a, customer b) {
		if (a.age < b.age) {
			// since we are building a minHeap based on customer age
			// when a.age is less than b.age we want to give a more
			// prioity so we are returning false
			return false;
		}
		return true;
	}

};

int main() {

	// we are building a minHeap of customers based on age

	priority_queue<customer, vector<customer>, ageComparator> m;

	m.push(customer("aman", 20, 150.1));
	m.push(customer("yash", 19, 1200));
	m.push(customer("prabhdeep", 21, 100));
	m.push(customer("devesh", 18, 140));
	m.push(customer("abhishek", 10, 1000));

	cout << m.size() << endl; // 5

	while (!m.empty()) {
		customer c = m.top();
		cout << c.name << " " << c.age << " " << c.balance << endl;
		m.pop();
	}

	cout << endl;

	cout << m.size() << endl;

	return 0;
}