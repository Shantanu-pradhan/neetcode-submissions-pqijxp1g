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
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        int res = 0;
        stack<pair<TreeNode *, int>>sstack;
        sstack.push({root, 1});
        while(!sstack.empty()){
            pair<TreeNode *, int>var = sstack.top();
            sstack.pop();
            TreeNode *node = var.first;
            int depth = var.second;
            res = max(res, depth);
            if(node->left){
                sstack.push({node->left, depth+1});
            }
            if(node->right){
                sstack.push({node->right, depth+1});
            }
        }
        return res;
    }
};
