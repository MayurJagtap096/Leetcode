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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> m;
        set<int> childrens;
        for(vector<int> & v: descriptions) {
            int parent = v[0];
            int child = v[1];
            int leftChild = v[2];

            if(m.find(parent) == m.end()) {
                m[parent] = new TreeNode(parent);   
            }
            if(m.find(child) == m.end()) {
                m[child] = new TreeNode(child);
            }
            if(leftChild) {
                m[parent]->left = m[child];
            }
            else {
                m[parent]->right = m[child];
            }
            childrens.insert(child);
        }

        // finding the root node
        for(vector<int>& v: descriptions) {
            int parent = v[0];
            if(childrens.find(parent) == childrens.end()) {
                return m[parent];
            }
        }
        return NULL;
    }
};