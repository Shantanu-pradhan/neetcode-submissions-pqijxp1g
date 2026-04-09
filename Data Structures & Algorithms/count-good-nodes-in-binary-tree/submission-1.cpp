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
    int goodNodes(TreeNode* root) {
        int res = good_node(root, root->val);
        return res;
    }

    int good_node(TreeNode *curr, int max_val){
        if(!curr){
            return 0;
        }
        int res = (curr->val >= max_val) ? 1:0;
        max_val = max(max_val, curr->val);
        res+=good_node(curr->left, max_val);
        res+=good_node(curr->right, max_val);
        return res;
    }
};
