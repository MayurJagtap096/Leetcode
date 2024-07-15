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

    void buildTree(TreeNode* root, const map<int,vector<int>> &m) {
        if (m.find(root->val) == m.end()) return; // Node not found in the map, return
        int leftChild = m.at(root->val)[0];
        int rightChild = m.at(root->val)[1];

        if(leftChild!=-1) {
            root->left = new TreeNode(leftChild);
            buildTree(root->left, m);
        }
        if(rightChild!=-1) {
            root->right = new TreeNode(rightChild);
            buildTree(root->right, m);
        }
    }
 
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,vector<int>> m;
        set<int> childrens;

        // storing the child nodes with parent node in a map
        for(vector<int> &v: descriptions) {
            int parent = v[0];
            int child = v[1];
            if (m.find(parent) == m.end()) {
                m[parent] = vector<int>(2, -1); // Initialize with -1 to indicate no child
            }
            if(v[2]) m[parent][0] = child;
            else m[parent][1] = child;
            childrens.insert(child);
        }

        // to find the root node
        int rootVal = -1;
        for(vector<int> &v: descriptions) {
            int parent = v[0];
            if(childrens.find(parent) == childrens.end()) {
                rootVal = parent;
                break;
            }
        }

        //build a tree
        TreeNode* root = new TreeNode(rootVal);
        buildTree(root, m);

        return root;
    }
};