/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> sol;
        vector<int> elements1, elements2;
        traverse(root1, elements1);
        traverse(root2, elements2);
        merge(elements1.begin(), elements1.end(), elements2.begin(), elements2.end(), back_inserter(sol));
        return sol;
    }
    void traverse(TreeNode* node, vector<int>& elements) {
        if(node == NULL) return;
        traverse(node->left, elements);
        elements.push_back(node->val);
        traverse(node->right, elements);
    }
};
