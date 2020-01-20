/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    FindElements(TreeNode* root) {
        recover(root, 0);
    }
    void recover(TreeNode* node, int value) {
        if(node == NULL) return;
        node->val = value;
        _elements.insert(value);
        recover(node->left, value * 2 + 1);
        recover(node->right, value * 2 + 2);
    }
    bool find(int target) {
        return _elements.count(target);
    }
private:
    unordered_set<int> _elements;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
