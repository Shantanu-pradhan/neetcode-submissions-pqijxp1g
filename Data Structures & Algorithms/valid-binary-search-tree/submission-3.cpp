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
    bool isValidBST(TreeNode* root) {
        return validate_btree(root, INT_MIN, INT_MAX);
    }
    bool validate_btree(TreeNode *curr, int left, int right){
        if(!curr){
            return true;
        }
        if(!(curr->val > left && curr->val < right)){
            return false;
        }
        return (validate_btree(curr->left, left, curr->val) && validate_btree(curr->right, curr->val, right));
    }
};
