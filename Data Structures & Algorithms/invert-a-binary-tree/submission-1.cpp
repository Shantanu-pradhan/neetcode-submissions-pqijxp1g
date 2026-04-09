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
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return nullptr;
        }
        queue<TreeNode *>qnode;
        qnode.push(root);
        while(!qnode.empty()){
            TreeNode *node = qnode.front();
            qnode.pop();
            swap(node->left, node->right);
            if(node->left){
                qnode.push(node->left);
            }
            if(node->right){
                qnode.push(node->right);
            }
        }
        return root;
    }
};
