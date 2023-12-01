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
    int maxi=-1;
    unordered_map<int,int> m;
    int solve(TreeNode* root){
        if(!root) return 0;
        int total = solve(root->left) + solve(root->right) + root->val;
        m[total]++;
        maxi = max(maxi,m[total]);
        return total;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        solve(root);
        vector<int> ans;
        for(auto a:m){
            if(a.second==maxi) ans.push_back(a.first);
        }
        return ans;
    }
};