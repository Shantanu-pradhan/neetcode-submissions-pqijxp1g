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
        queue<TreeNode *>qn;
        qn.push(root);
        while(!qn.empty()){
            int len = qn.size();
            TreeNode* rightside = nullptr;
            for(int i=0; i<len; i++){
                TreeNode *curr = qn.front();
                qn.pop();
                if(curr){
                    rightside = curr;
                    qn.push(curr->left);
                    qn.push(curr->right);
                }
            }
            if(rightside){
                res.push_back(rightside->val);
            }
        }
        return res;
    }
};
