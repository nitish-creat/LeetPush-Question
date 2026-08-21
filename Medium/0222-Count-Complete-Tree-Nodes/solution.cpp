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
    int leftheight(TreeNode* root){
        int lh = 0;
        while(root){
            lh++;
            root = root->left;
        }
        return lh;
    }
    int rightheight(TreeNode* root){
        int rh = 0;
        while(root){
            rh++;
            root = root->right;
        }
        return rh;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int left = leftheight(root);
        int right = rightheight(root);
        
        if(left == right){
            return pow(2 , left) - 1;
        }

        return countNodes(root->left) + countNodes(root->right) +1;
    }
};