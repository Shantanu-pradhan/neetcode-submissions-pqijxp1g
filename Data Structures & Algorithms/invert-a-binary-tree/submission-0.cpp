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
            return NULL;
        }
        queue<TreeNode *>tqueue;
        tqueue.push(root);
        while(!tqueue.empty()){
            TreeNode *node = tqueue.front();
            tqueue.pop();
            swap(node->left, node->right);
            if(node->left){
                tqueue.push(node->left);
            }
            if(node->right){
                tqueue.push(node->right);
            }
        }
        return root;
    }
};
