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
        int level = 0;
        if(!root){
            return level;
        }
        queue<TreeNode *>qnode;
        qnode.push(root);
        while(!qnode.empty()){
            int size = qnode.size();
            for(int i=0; i<size; i++){
                TreeNode *node = qnode.front();
                qnode.pop();
                if(node->left){
                    qnode.push(node->left);
                }
                if(node->right){
                    qnode.push(node->right);
                }
            }
            level++;
        }
        return level;
    }
};
