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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root == NULL) return NULL;
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        return (root->left == NULL && root->right == NULL && root->val == target) ? NULL : root;
    }
};
// class Solution {
// public:
//     TreeNode* removeLeafNodes(TreeNode* root, int target) {
//         _target = target;
//         traverse(root);
//         return remove(root) ? NULL : root;
//     }
//     void traverse(TreeNode* node) {
//         if(node == NULL) return;
//         traverse(node->left);
//         traverse(node->right);
//         if(node->left && remove(node->left)) node->left = NULL;
//         if(node->right && remove(node->right)) node->right = NULL;
//     }
//     bool remove(TreeNode* node) {
//         return node->left == NULL && node->right == NULL && node->val == _target;
//     }
// private:
//     int _target;
// };
