/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
void dfsSeralize(TreeNode* node,string &s){
        if(!node){
            s+="#,";
            return;
        }
        s+=to_string(node->val)+',';
        dfsSeralize(node->left,s);
        dfsSeralize(node->right,s);
    }
    TreeNode* dfsDeserialize(string& s,int &idx){
        if(s[idx]=='#'){
            idx+=2;
            return NULL;
        }
        int sign=1;
        if(s[idx]=='-'){
            sign=-1;
            idx++;
        }
        int num=0;
        while(s[idx]!=','){
            num=num*10+(s[idx]-'0');
            idx++;
        }
        idx++;
        TreeNode* node=new TreeNode(num*sign);
        node->left= dfsDeserialize(s,idx);
        node->right=dfsDeserialize(s,idx);
        return node;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       string s;
       dfsSeralize(root,s);
       return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
          int idx = 0;
        return dfsDeserialize(data, idx);
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));