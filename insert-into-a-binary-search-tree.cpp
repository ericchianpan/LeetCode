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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *node = root, *pre = NULL;
        while(node) {
            pre = node;
            node = val > node->val? node->right : node->left;
        }
        if(val > pre->val) pre->right = new TreeNode(val);
        else pre->left = new TreeNode(val);
        return root;
    }
};
