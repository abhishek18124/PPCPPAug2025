#include<iostream>
#include<cstring>

using namespace std;

// time : O(min(m, n)) where m and n are lengths of s1 and s2 respecitively

int stringCompare(char s1[], char s2[]) {

	int i = 0; // to iterate over s1[]
	int j = 0; // to iterate over s2[]

	while (s1[i] != '\0' and s2[j] != '\0') {

		if (s1[i] > s2[j]) {
			// s1 > s2
			return 1;
		} else if (s1[i] < s2[j]) {
			// s1 < s2
			return -1;
		} else {
			i++;
			j++;
		}

	}

	if (s1[i] != '\0' and s2[j] == '\0') {
		// len of s1 > len of s2 => s1 > s2
		return 1;
	} else if (s1[i] == '\0' and s2[j] != '\0') {
		// len of s1 < len of s2 => s1 < s2
		return -1;
	} else {
		// len of s1 is equal to len of s2
		return 0;
	}

}

int main() {

	char s1[] = "aac";
	char s2[] = "adc";

	// int res = stringCompare(s1, s2);
	int res = strcmp(s1, s2);

	cout << res << endl;

	if (res == 0) {
		cout << s1 << " is equal to " << s2 << endl;
	} else if (res > 0) {
		cout << s1 << " > " << s2 << endl;
	} else {
		cout << s1 << " < " << s2 << endl;
	}

	return 0;
}