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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        queue<TreeNode *>qn;
        qn.push(root);
        while(!qn.empty()){
            int size = qn.size();
            vector<int>qdata;
            for(int i=0; i<size; i++){
                TreeNode *node = qn.front();
                qn.pop();
                if(node){
                    qdata.push_back(node->val);
                    qn.push(node->left);
                    qn.push(node->right);
                }
            }
            if(!qdata.empty()){
                res.push_back(qdata);
            }
        }
        return res;
    }
};
