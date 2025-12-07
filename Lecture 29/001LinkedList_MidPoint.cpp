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

	while (head) { // head != NULL
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;

}

// time : n/2.const ~ O(n)

ListNode* findMidPoint(ListNode* head) {

	if (head == NULL) {
		return NULL;
	}

	ListNode* slow = head;
	ListNode* fast = head->next;

	while (fast != NULL and fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;

}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	ListNode* midPoint = findMidPoint(head);

	if (midPoint != NULL) {
		cout << midPoint->val << endl;
	} else {
		cout << "Linked List is empty" << endl;
	}

	return 0;
}