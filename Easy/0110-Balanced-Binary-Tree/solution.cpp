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
    int height(TreeNode* node){
        if(!node) return 0;
        queue<TreeNode*> q;

        q.push(node);
        int depth = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            depth++;
        }

        return depth;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int lefth = height(root->left);
        int righth = height(root->right);

        if(abs(lefth - righth) > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};