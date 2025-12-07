#include<iostream>

using namespace std;

class ListNode {
public:

	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}

};

void insertAtHead(ListNode*& head, int val) {
	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;
}

void printLinkedList(ListNode* head) {
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

// time : O(n)
// space: O(1)

ListNode* removeDuplicates(ListNode* head) {

	// in our implt. we are not changing the head

	ListNode* prev = head; // prev points to the last tracked node
	ListNode* cur = head->next; // cur is used to iterate over remaining linked list

	while (cur != NULL) {

		if (cur->val == prev->val) {
			// skip the cur node
			cur = cur->next;
		} else {
			// track the cur node
			prev->next = cur;
			prev = cur;
			cur = cur->next;
		}

	}

	prev->next = NULL; // the next field of the last tracked node should be null since the last tracked node is the tail of the linkedList

	return head;

}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 40);
	insertAtHead(head, 40);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 20);
	insertAtHead(head, 10);
	insertAtHead(head, 10);
	insertAtHead(head, 10);

	printLinkedList(head);

	head = removeDuplicates(head);

	printLinkedList(head);

	return 0;
}