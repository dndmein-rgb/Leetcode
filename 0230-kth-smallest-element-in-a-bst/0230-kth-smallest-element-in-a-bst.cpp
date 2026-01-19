/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int count = 0, ans = 0;

    void inorder(TreeNode* node, int k) {
        if (!node) return;

        inorder(node->left, k);

        count++;
        if (count == k) {
            ans = node->val;
            return; // stop early once kth element found
        }

        inorder(node->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        ans = 0;
        inorder(root, k);
        return ans;
    }
};
