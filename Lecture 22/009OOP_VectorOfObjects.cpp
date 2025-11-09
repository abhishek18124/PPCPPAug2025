#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class customer {

public:

	string name;
	int age;
	char gender;
	double credits;

	customer(string name, int age, char gender, double credits) {
		this->name = name;
		this->age = age;
		this->gender = gender;
		this->credits = credits;
	}
};

// return true if you want a to be ordered before b otherwise return false

bool creditsCmp(customer a, customer b) {
	if (a.credits > b.credits) {
		// since we are sorting vec<> of customers by the credits in the
		// dec. order therefore when a.credits is more than b.credits we
		// want a to be ordered before b hence we are returing true
		return true;
	} else {
		return false;
	}

	// return a.credits > b.credits;
}

class CreditsComp {
public:

	bool operator()(customer a, customer b) {
		if (a.credits > b.credits) {
			// since we are sorting vec<> of customers by the credits in the
			// dec. order therefore when a.credits is more than b.credits we
			// want a to be ordered before b hence we are returing true
			return true;
		} else {
			return false;
		}
	}

};

int main() {

	vector<customer> v;

	// customer c1("Ramanujan", 32, 'M', 1729);
	// v.push_back(c1);

	v.push_back(customer("Ramanujan", 32, 'M', 1729));
	v.push_back(customer("JC Bose", 78, 'M', 2500));
	v.push_back(customer("Aryabhata", 74, 'M', 0));
	v.push_back(customer("Vikram", 52, 'M', 1500));
	v.push_back(customer("Homi", 56, 'M', 1000));

	// sort(v.begin(), v.end(), creditsCmp);

	CreditsComp obj;

	sort(v.begin(), v.end(), obj);

	for (customer& c : v) { // here we are using & to avoid copy of customer objects
		cout << c.name << " " << c.age << " " << c.gender << " " << c.credits << endl;
	}

	vector<int> v1 = {2, 5, 0, 1, 4};

	// greater<int> obj1;

	// sort(v1.begin(), v1.end(), obj1);

	sort(v1.begin(), v1.end(), greater<int>());

	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}

	cout << endl;

	return 0;
}