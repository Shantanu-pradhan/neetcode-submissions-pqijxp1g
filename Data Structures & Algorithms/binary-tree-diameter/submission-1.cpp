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
        if(!root){
            return 0;
        }
        int maxdepth = max_depth(root->left)+max_depth(root->right);
        int maxdiam = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
        return max(maxdepth, maxdiam);
    }
    int max_depth(TreeNode *node){
        if(!node){
            return 0;
        }
        return (1 + max(max_depth(node->left) , max_depth(node->right)));
    }
};
