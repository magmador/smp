// https://leetcode.com/problems/validate-binary-search-tree/

#include <iostream>
#include <limits.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }

private:
    bool validate(TreeNode* node, long min_val, long max_val) {
        if (node == nullptr) return true;
        if (node->val <= min_val || node->val >= max_val) return false;

        return    validate(node->left, min_val, node->val)
               && validate(node->right, node->val, max_val);
    }
};

int main() {
    TreeNode *tree = new TreeNode(5, new TreeNode(4), new TreeNode(6, new TreeNode(3), new TreeNode(7)));
    Solution o;

    std::cout << "result: " << o.isValidBST(tree) << std::endl;

    return 0;
}
