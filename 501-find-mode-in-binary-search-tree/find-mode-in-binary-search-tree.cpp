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
    vector<int> ans;
    unordered_map<int,int> m;
    void solve(TreeNode* root){
        if(!root) return;
        m[root->val]++;
        solve(root->left);
        solve(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        solve(root);
        int mc=0;
        for(auto a:m){
            mc = max(mc,a.second);
        }
        for(auto a:m){
            if(a.second==mc) ans.push_back(a.first);
        }
        return ans;
    }
};