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
    int diameterOfBinaryTree(TreeNode* root) {
        int diam=0;
        if(!root){
            return 0;
        }
        cal_diam(root, diam);
        return diam;
    }
    int cal_diam(TreeNode *node, int &res){
        if(!node){
            return 0;
        }
        int left = cal_diam(node->left, res);
        int right = cal_diam(node->right, res);
        res = max(res, left+right);
        return 1+max(left, right);
    }
};
