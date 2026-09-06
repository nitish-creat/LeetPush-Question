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
    int solve(TreeNode* root, int &res){
        if(!root) return 0;
        int left = solve(root->left,res);
        int right = solve(root->right , res);
        int leftpath = 0;
        int rightpath = 0;

        if(root->left && root->left->val == root->val){
            leftpath = left+1;
        }
        if(root->right && root->right->val == root->val){
            rightpath = right+1;
        }

        res = max(res , leftpath + rightpath);
        return max(leftpath , rightpath);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int res = INT_MIN;
        solve(root , res);

        return res;
    }
};