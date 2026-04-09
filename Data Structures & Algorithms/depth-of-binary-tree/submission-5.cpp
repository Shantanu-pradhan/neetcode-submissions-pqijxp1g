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
        stack<pair<TreeNode *, int>>sstack;
        sstack.push({root, 1});
        int res = 0;
        while(!sstack.empty()){
            pair<TreeNode *, int>p = sstack.top();
            sstack.pop();
            int depth = p.second;
            TreeNode *node = p.first;
            if(node != nullptr){
                res = max(res, depth);
                sstack.push({node->left,depth+1});
                sstack.push({node->right, depth+1});
            }
            
        }
        return res;
    }
};
