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
    TreeNode* bstToGst(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* node = root;
        int sum = 0;
        while(node || !s.empty()) {
            while(node) {
                s.push(node);
                node = node->right;
            }
            
            node = s.top();
            s.pop();
            
            sum += node->val;
            node->val = sum;
            
            node = node->left;
        }
        return root;
    }
};
