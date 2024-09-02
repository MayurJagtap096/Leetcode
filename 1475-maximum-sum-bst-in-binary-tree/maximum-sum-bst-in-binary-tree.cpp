/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class info {
public:
    int maxVal;
    int minVal;
    int sum;
    bool isBST;
};
class Solution {
public:
    info solve(TreeNode* root, int& sum) {
        if (root == NULL) {
            info temp;
            temp.maxVal = INT_MIN;
            temp.minVal = INT_MAX;
            temp.sum = 0;
            temp.isBST = true;
            sum = max(temp.sum, sum);
            return temp;
        }

        info leftAns = solve(root->left, sum);
        info rightAns = solve(root->right, sum);

        info currAns;
        currAns.maxVal = max(leftAns.maxVal, max(rightAns.maxVal, root->val));
        currAns.minVal = min(leftAns.minVal, min(rightAns.minVal, root->val));
        currAns.sum = leftAns.sum + rightAns.sum + root->val;
        currAns.isBST = (root->val > leftAns.maxVal && root->val < rightAns.minVal && leftAns.isBST && rightAns.isBST);
        if (currAns.isBST)
            sum = max(currAns.sum, sum);
        return currAns;
    }
    int maxSumBST(TreeNode* root) {
        int sum = 0;
        solve(root, sum);
        return sum;
    }
};