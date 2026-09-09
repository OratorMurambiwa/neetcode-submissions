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
    int count = 0;
    int answer = 0;

    void check(TreeNode* node, int k) {

        if (node == nullptr) {
            return;
        }

        check(node->left, k);

        count += 1;

        if (count == k) {
            answer = node->val;
            return;
        }

        check(node->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        check(root, k);
        return answer;
    }
};
