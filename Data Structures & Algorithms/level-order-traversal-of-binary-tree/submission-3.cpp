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
        queue<TreeNode *>qn;
        vector<vector<int>>res;
        if(root == NULL){
            return res;
        }
        qn.push(root);
        while(!qn.empty())
        {
            int len = qn.size();
            vector<int>temp;
            for(int i=0; i<len; ++i){
                TreeNode *curr = qn.front();
                qn.pop();
                temp.push_back(curr->val);
                if(curr->left)
                    qn.push(curr->left);
                if(curr->right)
                    qn.push(curr->right);
            }
            if(!temp.empty()){
                res.push_back(temp);
            }
        }
        return res;
    }

};
