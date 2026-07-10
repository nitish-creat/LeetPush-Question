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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder , int instart, int pstart , int inend, int pend){

        if( instart > inend) return NULL;
        TreeNode* node = new TreeNode(postorder[pend]);
        int i = instart;
        for( ; i<= inend ;i++){
            if(inorder[i] == node->val) break;
        }
        int leftsize = i - instart;
        int rightsize = inend - i;

        node->left = solve(inorder, postorder, instart, pstart , i-1 , pstart + leftsize - 1);
        node->right = solve(inorder, postorder, i+1, pend - rightsize , inend , pend - 1);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int instart = 0;
        int inend = n-1;
        int pstart = 0;
        int pend = n-1;

        return solve(inorder , postorder, instart , pstart , inend , pend);
    }
};