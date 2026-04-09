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
        //create a stack
        if(!root){
            return 0;
        }
        stack<pair<TreeNode *, int>>tstack;
        tstack.push({root, 1});
        int res = 0;
        while(!tstack.empty()){
            pair <TreeNode *, int>element = tstack.top();
            tstack.pop();
            TreeNode *node = element.first;
            int depth = element.second;
            res = max(res,depth);
            if(node->left){
                tstack.push({node->left, depth+1});
            }
            if(node->right){
                tstack.push({node->right, depth+1});
            }
        }
        return res;
    }
};
