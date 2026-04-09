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
        if(!root){
            return res;
        }
        queue<TreeNode *>qn;
        qn.push(root);
        int i=0;
        while(!qn.empty()){
            int size = qn.size();
            vector<int>lvector;
            res.push_back(lvector);
            for(int j=0; j<size; j++){
                TreeNode *node = qn.front();
                qn.pop();
                res[i].push_back(node->val);
                if(node->left){
                    qn.push(node->left);
                }
                if(node->right){
                    qn.push(node->right);
                }
            }
            i++;
        }
        return res;
    }
};
