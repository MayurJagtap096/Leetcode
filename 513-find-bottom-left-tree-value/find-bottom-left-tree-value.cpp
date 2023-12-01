class Solution {
public:
    int maxDepth = -1;
    TreeNode* ret;
    void dfs(TreeNode* root, int depth){
        if(!root) return;
        if(depth > maxDepth) ret = root, maxDepth = depth;
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root,0);
        return ret->val;
    }
};