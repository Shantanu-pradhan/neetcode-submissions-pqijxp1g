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
        if(!root){
            return true;
        }
        if(is_valid(root, LONG_MIN, LONG_MAX)){
            return true;
        }
        return false;
    }

    bool is_valid(TreeNode* node, long min_val, long max_val){
        if(!node){
            return true;
        }
        if(!((node->val > min_val) && (node->val < max_val))){
            return false;
        }
        return (is_valid(node->left, min_val, node->val) && is_valid(node->right, node->val, max_val));
    }

};
