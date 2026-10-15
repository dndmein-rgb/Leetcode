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
bool dfs(TreeNode* root,long leftLimit,long rightLimit){
    if(!root)return true;
    if(root->val <=leftLimit || root->val>=rightLimit)return false;
    return dfs(root->left,leftLimit,root->val) && dfs(root->right,root->val,rightLimit);
}
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
     return dfs(root,LONG_MIN,LONG_MAX);
    }
};