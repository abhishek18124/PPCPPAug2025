/*

	Implement a phonebook storing mapping between person's name and
	their phone numbers using an unordered_map.

*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main() {

	unordered_map<string, vector<string>> phoneMap;

	phoneMap["Gopal"].push_back("965488670");
	phoneMap["Gopal"].push_back("123456789");
	phoneMap["Gopal"].push_back("000000000");

	phoneMap["Aman"].push_back("1111111111");
	phoneMap["Aman"].push_back("2222222222");

	for (pair<string, vector<string>> p : phoneMap) {
		string contactName = p.first; // key
		vector<string> phoneNums = p.second; // value corr. to key
		cout << contactName << " : ";
		for (string num : phoneNums) {
			cout << num << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (auto [contactName, phoneNums] : phoneMap) {
		cout << contactName << " : ";
		for (string num : phoneNums) {
			cout << num << " ";
		}
		cout << endl;
	}

	return 0;
}