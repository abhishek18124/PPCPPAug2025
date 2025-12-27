/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

	bool dfs(TreeNode* root, int t) {

		// base case

		if (root == NULL) {
			return false;
		}

		if (root->left == NULL and root->right == NULL) {
			if (root->val == t) {
				// you've found a valid path
				return true;
			} else {
				// current path is not valid
				return false;
			}
		}

		// recursive case

		// 1. ask your friend to check if there is root-to-leaf path in the leftSubtree
		// whose sum is t - root->val

		// 2. ask your friend to check if there is root-to-leaf path in the rightSubtree
		// whose sum is t - root->val

		return dfs(root->left, t - root->val) or dfs(root->right, t - root->val);

	}

	bool hasPathSum(TreeNode* root, int targetSum) {

		return dfs(root, targetSum);

	}
};