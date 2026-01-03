/*

	Given a binary tree, design an algorithm to check if is a BST or not.

*/

#include<iostream>
#include<climits>

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

int findMinimum(TreeNode* root) {

	if (root == NULL) {
		return INT_MAX;
	}

	while (root->left != NULL) {
		root = root->left;
	}

	return root->val;

}

int findMaximum(TreeNode* root) {

	if (root == NULL) {
		return INT_MIN;
	}

	while (root->right != NULL) {
		root = root->right;
	}

	return root->val;

}

bool checkBST(TreeNode* root) {

	// base case

	if (root == NULL) {
		return true;
	}

	// recursive case

	// f(root) : check if the given tree is a bst

	// 1. ask your friend to check if the leftSubtree is a BST

	bool leftIsBst = checkBST(root->left);

	// 2. ask your friend to check if the rightSubtree is a BST

	bool rightIsBst = checkBST(root->right);

	// 3. check if the BST prop. works at the root node

	bool isBstPropWorkingAtRoot = root->val > findMaximum(root->left) and root->val < findMinimum(root->right) ? true : false;

	return leftIsBst and rightIsBst and isBstPropWorkingAtRoot;

}

class triple {
public:
	bool isbst;
	int minval;
	int maxval;
};

triple checkBSTOptimised(TreeNode* root) {

	triple t;

	// base case

	if (root == NULL) {
		t.isbst = true;
		t.minval = INT_MAX;
		t.maxval = INT_MIN;
		return t;
	}

	// recursive case

	// f(root) : check if the given tree is a bst

	// 1. ask your friend to check if the leftSubtree is a BST

	triple left = checkBSTOptimised(root->left);

	// 2. ask your friend to check if the rightSubtree is a BST

	triple right = checkBSTOptimised(root->right);

	// 3. check if the BST prop. works at the root node

	bool isBstPropWorkingAtRoot = root->val > left.maxval and root->val < right.minval ? true : false;

	t.isbst = left.isbst and right.isbst and isBstPropWorkingAtRoot;
	t.minval = min(left.minval, min(right.minval, root->val));
	t.maxval = max(left.maxval, max(right.maxval, root->val));

	return t;

}

int main() {

	TreeNode* root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(17);

	checkBST(root) ? cout << "bst" << endl : cout << "not bst" << endl;

	triple t = checkBSTOptimised(root);

	t.isbst ? cout << "bst" << endl : cout << "not bst" << endl;

	return 0;
}