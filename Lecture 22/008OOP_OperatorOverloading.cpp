#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

	customer(string n, int a, char g, double c) {
		cout << "\ninside the parameterised constructor of the \'customer\' class\n" << endl;
		name = n;
		age = a;
		gender = g;
		credits = c;
	}

	void print() {
		cout << "name = " << name << endl;
		cout << "age = " << age << endl;
		cout << "gender = " << gender << endl;
		cout << "credits = " << credits << endl << endl;
	}

	int operator+(customer c) { // here c is copy of c2 // pass c2 by ref to avoid copy
		cout << "age = " << age << endl;
		cout << "c.age = " << c.age << endl;
		return age +  c.age;
	}

	// overloading as a member fn
	bool operator>(customer c) { // here c is a copy of c2 // pass c2 by ref to void copy
		return credits > c.credits;
	}

};

int operator*(customer c1, customer c2) { // overloading as a non-member fn
	return c1.age * c2.age;
}

int main() {

	customer c1("Ramanujan", 32, 'M', 1729);
	customer c2("Aryabhata", 74, 'M', 0);

	cout << c1 + c2 << endl; // c1.operator+(c2)
	cout << c1.operator + (c2) << endl;

	if (c1 > c2) { // c1.operator>(c2)
		cout << c1.name << " " << c2.name << " se ameer hai" << endl;
	} else {
		cout << c2.name << " " << c1.name << " se ameer hai" << endl;
	}

	cout << c1 * c2 << endl; // c1.operator*(c2)  // operator*(c1, c2)

	return 0;

}