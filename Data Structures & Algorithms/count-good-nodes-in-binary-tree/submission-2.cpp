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
        int count = 0;
        if(!root){
            return 0;
        }
        return count_node(root, root->val);
    }
    int count_node(TreeNode* node, int val){
        int res = 0;
        if(!node){
            return 0;
        }
        res = (node->val >= val) ? 1:0;
        val = max(node->val, val);
        res += count_node(node->left, val);
        res += count_node(node->right, val);
        return res; 

    }
};









