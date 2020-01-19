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
    int pre = -1;
    int sol = INT_MAX;
    int minDiffInBST(TreeNode* root) {
        if(root == NULL) return 0;
        inorder(root);
        return sol;
    }
    
    void inorder(TreeNode* node) {
        if(node == NULL) return;
        inorder(node->left);
        if(pre >= 0) sol = min(sol, node->val - pre);
        pre = node->val;
        inorder(node->right);
    }
};
