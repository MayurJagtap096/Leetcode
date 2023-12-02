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
    vector<string> v;
    void solve(TreeNode* root,string temp){
        if(!root) return;
        temp += to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            v.push_back(temp);
            cout<<temp<<" "; 
            return;
        }
        solve(root->left,temp);
        solve(root->right,temp);
    }
    int sumRootToLeaf(TreeNode* root) {
        solve(root,"");
        int ans=0;
        for(string s:v){
            int num = stoi(s,0,2);
            ans+=num;
        }
        return ans;
    }
};