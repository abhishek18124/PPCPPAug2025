/*
		https://cplusplus.com/reference/utility/pair/?kw=pair

		This 'pair' class couples together a pair of values, which maybe of different
		types (T1 and T2).The individual values of a pair can be accessed through its
		public members first and second.
*/

#include<iostream>
#include<utility>

using namespace std;

int main() {

	pair<int, int> p1;
	p1.first = 20;
	p1.second = 100;

	cout << p1.first << " " << p1.second << endl;

	pair<string, int> p2;
	p2.first = "hello";
	p2.second = 50;

	cout << p2.first << " " << p2.second << endl;

	pair<char, int> p3;
	p3.first = 'X';
	p3.second = 10;

	cout << p3.first << " " << p3.second << endl;

	pair<int, int> p4;
	cin >> p4.first >> p4.second;
	cout << p4.first << " " << p4.second << endl;

	pair<int, int> p5 = {100, 200};
	cout << p5.first << " " << p5.second << endl;

	pair<int, int> p6 = make_pair(50, 60);
	cout << p6.first << " " << p6.second << endl;

	return 0;
}