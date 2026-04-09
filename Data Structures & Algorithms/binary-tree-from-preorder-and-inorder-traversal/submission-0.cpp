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
    int root_indx = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int, int>umap;
        for(int i=0; i<inorder.size(); i++){
            umap[inorder[i]] = i;
        }
        TreeNode *root = create_tree(preorder, umap, 0, inorder.size()-1);
        return root;
    }
    TreeNode* create_tree(vector<int>& preorder, unordered_map<int, int>&umap, int l, int r)
    {
        if(l > r){
            return NULL;
        }
        int root_val = preorder[root_indx++];
        int mid = umap[root_val];
        TreeNode *root = new TreeNode(root_val);
        root->left = create_tree(preorder, umap, l, mid-1);
        root->right = create_tree(preorder, umap, mid+1, r);
        return root;
    }
};
