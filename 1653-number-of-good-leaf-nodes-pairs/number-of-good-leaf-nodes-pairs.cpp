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
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        countPairsUtil(root, distance, ans);
        return ans;
    }
    
private:
    // Helper function for DFS traversal and pair counting
    vector<int> countPairsUtil(TreeNode* root, int distance, int& ans) {
        if (!root) return {};
        
        // Leaf node case
        if (!root->left && !root->right) return {1};
        
        // Get the distances from left and right subtrees
        vector<int> leftDistances = countPairsUtil(root->left, distance, ans);
        vector<int> rightDistances = countPairsUtil(root->right, distance, ans);
        
        // Count valid pairs from left and right subtrees
        for (int l : leftDistances) {
            for (int r : rightDistances) {
                if (l + r <= distance) {
                    ans++;
                }
            }
        }
        
        // Increase all distances by 1 and merge left and right distances
        vector<int> newDistances;
        for (int l : leftDistances) {
            if (l + 1 <= distance) newDistances.push_back(l + 1);
        }
        for (int r : rightDistances) {
            if (r + 1 <= distance) newDistances.push_back(r + 1);
        }
        
        return newDistances;
    }

};