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

    bool solve(TreeNode* root)
    {
        if(!root) return false;
        if(root->left==NULL && root->right==NULL) return root->val;
        if(root->val==2)
        {
            root->val = solve(root->left) || solve(root->right);
        }
        if(root->val==3)
        {
            root->val = solve(root->left) && solve(root->right);
        }
        return root->val;
    }

    bool evaluateTree(TreeNode* root) 
    {
        return solve(root);
    }
};