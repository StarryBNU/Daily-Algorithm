#include <iostream>
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isValidBSTHelper(TreeNode* node, long long minVal, long long maxVal) {
    if (!node) return true;

    if (node->val <= minVal || node->val >= maxVal)
        return false;

    return isValidBSTHelper(node->left, minVal, node->val) &&
           isValidBSTHelper(node->right, node->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
}
int main() {
    // 构建一个 BST:     5
    //                  / \
    //                 3   8
    //                / \ / \
    //               2  4 7  9
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    std::cout << (isValidBST(root) ? "true" : "false") << std::endl; // 输出 true

    // 修改一个节点使其非法：比如让右子树出现 5
    root->right->left = new TreeNode(5); // 违反 BST（5 不大于根 5）
    std::cout << (isValidBST(root) ? "true" : "false") << std::endl; // 输出 false

    return 0;
}
