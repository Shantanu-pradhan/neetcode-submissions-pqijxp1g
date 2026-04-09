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
    unordered_map<int, int>umap;
    int indx = 0;
    TreeNode* constr_tree(vector<int>&preorder, int left, int right){
        if(left > right){
            return nullptr;
        }
        int root_val = preorder[indx++];
        TreeNode *root = new TreeNode(root_val);
        int mid = umap[root_val];
        root->left = constr_tree(preorder, left, mid-1);
        root->right = constr_tree(preorder, mid+1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<= inorder.size()-1; i++){
            umap[inorder[i]] = i;
        }
        return constr_tree(preorder, 0, umap.size()-1);
    }
};
