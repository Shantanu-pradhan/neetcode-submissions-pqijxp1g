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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot){
            return true;
        }
        if(!root){
            return false;
        }
        if(ck_node(root, subRoot)){
            return true;
        }
        //check if other nodes of the root tree has the subtree
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    bool ck_node(TreeNode *n1, TreeNode *m1){
        if(!n1 && !m1){
            return true;
        }
        if(n1 && m1 && (n1->val == m1->val)){
            return ck_node(n1->left, m1->left) &&
            ck_node(n1->right, m1->right);
        }
        return false;
    }
};
