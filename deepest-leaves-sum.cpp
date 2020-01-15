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
    vector<int> sum;
    int deepestLeavesSum(TreeNode* root) {
        traverse(root, 0);
        return (sum.back());
    }
    void traverse(TreeNode* node, int level) {
        if(!node) return;
        if(sum.size() < level + 1) sum.push_back(node->val);
        else sum[level] += node->val;
        traverse(node->left, level + 1);
        traverse(node->right, level + 1);
    }
};
