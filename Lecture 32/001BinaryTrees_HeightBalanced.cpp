
/*
given the pre-order traversal of a binary tree, check if it is height balanced or not

Example
	Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
	Output: true

	Input : 10 20 40 -1 -1 50 -1 -1 30 60 -1 -1 70 -1 -1
	Output: true

	Input : 10 20 30 -1 -1 -1 -1
	Output: false

*/

#include<iostream>
#include<cmath>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};


TreeNode* buildTree() {

	int val;
	cin >> val;

	// base case

	if (val == -1) {
		// construct an empty tree and return pointer to its root TreeNode
		return NULL;
	}

	// recursive case

	// 1. construct the root val using the first value of the given preOrder traversal

	TreeNode* root = new TreeNode(val);

	// 2. ask your friend to construct the leftSubtree from the preOrder traversal of the leftSubtree

	root->left = buildTree();

	// 3. ask your friend to construct the rightSubtree from the preOrder traversal of the rightSubtree

	root->right = buildTree();

	return root;

}

int computeHeight(TreeNode* root) {

	// base case

	if (!root) { // root == NULL
		// height of empty tree is -1
		return -1;
	}

	// recursive case

	// 1. recursively, compute the height of the leftSubtree
	int leftHgt = computeHeight(root->left);

	// 2. recursively, compute the height of the rightSubtree
	int rightHgt = computeHeight(root->right);

	return 1 + max(leftHgt, rightHgt);

}

// time : O(n^2)
// space: O(height of the tree)

bool checkHeightBalanced(TreeNode* root) {

	// base case

	if (root == NULL) {
		// tree is empty
		return true;
	}

	// recursive case

	// check if the given tree is height-balanced or not

	// 1. ask your friend to check if the leftsubtree is height-balanced or not

	bool leftIsBal = checkHeightBalanced(root->left);

	// 2. ask your friend to check if the rightsubtree is height-balanced or not

	bool rightIsBal = checkHeightBalanced(root->right);

	// 3. check if the height-balance prop. works at the root node

	bool doesHBPropWorkAtRoot = abs(computeHeight(root->left) - computeHeight(root->right)) <= 1 ? true : false;

	return leftIsBal and rightIsBal and doesHBPropWorkAtRoot;

}

class Pair {
public:
	int hgt;
	bool isbal;
};

// time : O(n)
// space: O(height of tree)

Pair checkHeightBalancedOptimised(TreeNode* root) {

	Pair p;

	// base case

	if (root == NULL) { // tree is empty
		p.hgt = -1;
		p.isbal = true;
		return p;
	}

	// recursive case

	// 1. ask your friend to check if the LST is HB or not and simultaneously find the hgt. of the LST
	Pair left = checkHeightBalancedOptimised(root->left);

	// 2. ask your friend to check if the RST is HB or not and simultaneously find the hgt. of the RST
	Pair right = checkHeightBalancedOptimised(root->right);

	// 3. check if the height-balance prop. works at the root node
	bool doesHBPropWorkAtRoot = abs(left.hgt - right.hgt) <= 1 ? true : false;

	p.hgt = 1  + max(left.hgt, right.hgt);
	p.isbal = left.isbal and right.isbal and doesHBPropWorkAtRoot;

	return p;
}


pair<int, bool> checkHeightBalancedOptimised2(TreeNode* root) {

	pair<int, bool> p;

	// base case

	if (root == NULL) { // tree is empty
		p.first = -1;
		p.second = true;
		return p;
	}

	// recursive case

	// 1. ask your friend to check if the LST is HB or not and simultaneously find the hgt. of the LST
	pair<int, bool> left = checkHeightBalancedOptimised2(root->left);

	// 2. ask your friend to check if the RST is HB or not and simultaneously find the hgt. of the RST
	pair<int, bool> right = checkHeightBalancedOptimised2(root->right);

	// 3. check if the height-balance prop. works at the root node
	bool doesHBPropWorkAtRoot = abs(left.first - right.first) <= 1 ? true : false;

	p.first = 1  + max(left.first, right.first);
	p.second = left.second and right.second and doesHBPropWorkAtRoot;

	return p;
}

int main() {

	TreeNode* root = buildTree();

	checkHeightBalanced(root) ? cout << "height-balanced!" << endl : cout << "not height-balanced" << endl;

	Pair p = checkHeightBalancedOptimised(root);

	p.isbal ? cout << "height-balanced" << endl : cout << "not-height-balanced" << endl;

	pair<int, bool> p2 = checkHeightBalancedOptimised2(root);

	p2.second ? cout << "height-balanced" << endl : cout << "not-height-balanced" << endl;

	return 0;
}