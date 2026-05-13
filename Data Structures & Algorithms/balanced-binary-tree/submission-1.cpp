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

    int height(TreeNode* root, int &dif){
        if(!root) return 0;
        int lh = height(root->left, dif);
        int rh = height(root->right, dif);
        if (abs(lh - rh) > 1) dif = 2;
        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int dif = -1;
        height(root, dif);
        return dif>1 ? false : true;
    }
};
