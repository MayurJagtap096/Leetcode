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
    set<int> s;
    void solve(TreeNode* root){
        if(!root) return;
        s.insert(root->val);
        solve(root->left);
        solve(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        solve(root);
        if(s.size()==1) return -1;
        vector<int> v;
        for(auto a:s){
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        return v[1];
    }
};