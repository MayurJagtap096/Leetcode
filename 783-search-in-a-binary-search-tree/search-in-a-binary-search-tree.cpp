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

    TreeNode* solve(TreeNode* node, int val)
    {
        if(node==NULL) return NULL;

        if(node->val == val)    
            return node;

        if(node->val > val) return solve(node->left, val);
        
        return solve(node->right, val);
    }

    TreeNode* searchBST(TreeNode* root, int val) 
    {
        return solve(root, val);
    }
};
