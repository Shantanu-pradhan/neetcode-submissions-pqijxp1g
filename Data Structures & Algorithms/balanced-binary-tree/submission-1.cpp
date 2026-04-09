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
    bool isBalanced(TreeNode* root) {
        bool res = true;
        if(!root || (res == false)){
            return res;
        }
        int left = cal_height(root->left);
        int right = cal_height(root->right);
        if(left - right > 1 || left - right < -1){
            res = false;
            return res; 
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int cal_height(TreeNode *node){
        if(!node){
            return 0;
        }
        int left = cal_height(node->left);
        int right = cal_height(node->right);
        return (1+max(left,right));
    }
};
