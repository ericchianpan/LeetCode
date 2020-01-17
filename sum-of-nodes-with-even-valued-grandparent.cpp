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
    int sumEvenGrandparent(TreeNode* root) {
        if(root == NULL) return 0;
        int res = sumEvenGrandparent(root->left) + sumEvenGrandparent(root->right);
        if(!(root->val & 1) && root->left) {
            if(root->left->left) res += root->left->left->val;
            if(root->left->right) res += root->left->right->val;
        }
        if(!(root->val & 1) && root->right) {
            if(root->right->left) res += root->right->left->val;
            if(root->right->right) res += root->right->right->val;
        }
        return res;
    }
};
