/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return root;
        TreeNode* node=root;
        if(node->val >p->val && node->val >q->val){
           return lowestCommonAncestor(node->left,p,q);
        }
        else if(node->val<p->val && node->val<q->val){
            return lowestCommonAncestor(node->right,p,q);
        }
        return node;
    }
};