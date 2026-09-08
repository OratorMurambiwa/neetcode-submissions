class Solution {
public:
    int res = 0;

    int get_height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = get_height(root->left);
        int right = get_height(root->right);

        int diameter = left + right;

        res = max(res, diameter);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        get_height(root);

        return res;
    }
};