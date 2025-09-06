#include<iostream>

using namespace std;

int x = 100;

int main() {

	cout << x << endl;

	int x = 10;

	cout << x << endl;

	{

		int x = 30;
		int y = 20;

		cout << x << " " << y << endl;

		{

			int x = 40;
			int y = 50;
			int z = 60;

			cout << x << " " << y << " " << z << endl;

		}

		cout << x << " " << y << endl;

	}

	cout << x << endl;


	return 0;
}