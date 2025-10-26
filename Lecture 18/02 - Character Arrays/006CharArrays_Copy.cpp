#include<iostream>
#include<cstring>

using namespace std;

int main() {

	char s1[100] = "abcde";
	char s2[] = "xyz";

	cout << s1 << endl;

	strcpy(s1, s2);

	cout << s1 << endl;

	return 0;
}