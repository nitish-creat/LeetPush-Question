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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode* , TreeNode*>> q;
        q.push({root,nullptr});
        while(!q.empty()){
            int size = q.size();
            TreeNode* parentx = NULL;
            TreeNode* parenty = NULL;
            for(int i = 0;i<size;i++){
                auto [node , parent] = q.front();
                q.pop();

                if(node->val == x){
                    parentx = parent;
                }
                else if(node->val == y){
                    parenty = parent;
                }
                if(node->left){
                    q.push({node->left , node});
                }
                if(node->right){
                    q.push({node->right , node});
                }
            }

            if(parentx && parenty){
                return parentx != parenty;
            }
            if(parentx || parenty) return false;
        }
        return false;
    }
};