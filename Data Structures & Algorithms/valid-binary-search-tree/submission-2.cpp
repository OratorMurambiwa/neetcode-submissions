/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    bool valid(TreeNode* node,long long minval, long long maxval) {

        if (node == nullptr) {
            return true;
        }

        if (node->val <= minval || node->val >= maxval) {
            return false;
        }

        bool leftcheck = valid(node->left, minval, node->val);
        bool rightcheck = valid(node->right, node->val, maxval);

        return leftcheck && rightcheck;
    }
    
    bool isValidBST(TreeNode* root) {

        return valid(root, LLONG_MIN, LLONG_MAX);
        
    }
};
