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
    int dfs(TreeNode* node,int value){
        if(!node)return 0;
        if(node->val>=value){
           return 1+dfs(node->left,node->val)+
            dfs(node->right,node->val);
        }
        return dfs(node->left,value)+dfs(node->right,value);

    }
    int goodNodes(TreeNode* root) {
        return 1+ dfs(root->left,root->val)+
        dfs(root->right,root->val);
    }
};