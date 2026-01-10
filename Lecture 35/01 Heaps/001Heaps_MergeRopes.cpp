/*

    There are given n ropes of different lengths, we need to connect these ropes into one rope.
    The cost to connect two ropes is equal to the sum of their lengths. We need to connect the
    ropes with minimum cost.

    Example :

    Input : {4, 3, 2, 6}
    Output: 29

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

    vector<int> ropeLengths = {4, 3, 2, 6};

    // priority_queue<int, vector<int>, greater<int>> minHeap;

    // for(int len : ropeLengths) {
    //     minHeap.push(len);
    // }

    // time : O(nlogn) // space : O(n) due to minHeap

    priority_queue<int, vector<int>, greater<int>> minHeap(ropeLengths.begin(), ropeLengths.end());

    int total = 0;

    while (minHeap.size() > 1) {

        int firstSmallest = minHeap.top();
        minHeap.pop();

        int secondSmallest = minHeap.top();
        minHeap.pop();

        total += firstSmallest + secondSmallest;
        minHeap.push(firstSmallest + secondSmallest);
    }

    cout << total << endl;

    return 0;

}