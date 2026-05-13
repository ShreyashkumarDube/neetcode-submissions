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

    bool solve(TreeNode* p, TreeNode* q){
        if(p==NULL || q==NULL) return p==q;

        return (p->val == q->val) && solve(p->right, q->right) && solve(p->left, q->left);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root || !root->val) return false;

        if(solve(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
