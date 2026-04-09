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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        queue<TreeNode *>node;
        node.push(root);
        while(!node.empty()){
            int len = node.size();
            TreeNode *tmp = nullptr;
            TreeNode *resnode = nullptr;
            for(int i=0; i<len; i++){
                tmp = node.front();
                node.pop();
                if(tmp){
                    resnode = tmp;
                    if(tmp->left){
                        node.push(tmp->left);
                    }
                    if(tmp->right){
                        node.push(tmp->right);
                    }
                }
            }
            if(resnode){
                res.push_back(resnode->val);
            }
        }
        return res;
    }
};








