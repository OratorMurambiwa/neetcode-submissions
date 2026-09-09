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

    bool isSame(TreeNode* tree1, TreeNode* tree2){

        if (tree1 == nullptr && tree2 == nullptr) {
            return true;
        }

        if (tree1 == nullptr || tree2 == nullptr) {
            return false;
        }

        if (tree1->val != tree2->val) {
            return false;
        }

        bool left = isSame(tree1->left, tree2->left);
        bool right = isSame(tree1->right, tree2->right);

        return left && right;
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if (root == nullptr) {
            return false;
        }

        if (isSame(root, subRoot)) {
            return true;
        }

        bool left_search = isSubtree(root->left, subRoot);
        bool right_search = isSubtree(root->right, subRoot);

        return left_search || right_search;
        
    }
};
