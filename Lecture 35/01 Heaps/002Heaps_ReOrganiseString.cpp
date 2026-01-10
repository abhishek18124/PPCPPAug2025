
#include<iostream>
#include<queue>

using namespace std;

string reorganise(const string& str) {

    int freq[26] = {0};

    for (char ch : str) {
        freq[ch - 'a']++;
    }

    // for (int i = 0; i < 26; i++) {
    //     cout << freq[i] << endl;
    // }

    priority_queue<pair<int, char>> maxHeap; // maxHeap<freq, char>

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            maxHeap.push({freq[i], i + 'a'});
            // maxHeap.push(make_pair(freq[i], i + 'a'));
        }
    }

    // while (!maxHeap.empty()) {
    //     pair<int, char> p = maxHeap.top();
    //     cout << p.first << " " << p.second << endl;
    //     maxHeap.pop();
    // }

    string ans = "";

    while (!maxHeap.empty()) {

        if (maxHeap.size() == 1) {
            pair<int, char> maxPair = maxHeap.top();
            maxHeap.pop();
            if (maxPair.first == 1) {
                ans += maxPair.second;
            } else {
                ans = "";
            }
        } else {

            // maxHeap.size() >= 2

            pair<int, char> firstMaxPair = maxHeap.top();
            maxHeap.pop();

            pair<int, char> secondMaxPair = maxHeap.top();
            maxHeap.pop();

            // ans = ans + string(1, firstMaxPair.second);
            ans += firstMaxPair.second;
            firstMaxPair.first--;

            ans += secondMaxPair.second;
            secondMaxPair.first--;

            if (firstMaxPair.first > 0) {
                maxHeap.push(firstMaxPair);
            }

            if (secondMaxPair.first > 0) {
                maxHeap.push(secondMaxPair);
            }

        }

    }

    return ans;

}

int main() {

    string str = "aaaaabbbbcccdd";

    cout << reorganise(str) << endl;

    return 0;
}