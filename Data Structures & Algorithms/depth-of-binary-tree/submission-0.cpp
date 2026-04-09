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
        if(!root){
            return 0;
        }
        queue<TreeNode *>qn;
        qn.push(root);
        int level = 0;
        while(!qn.empty()){
            int size = qn.size();
            for(int i=0; i<size; i++){
                TreeNode *node = qn.front();
                qn.pop();
                if(node->left){
                    qn.push(node->left);
                } 
                if(node->right){
                    qn.push(node->right);
                }
            }
            level++;
        }
        return level;
    }
};
