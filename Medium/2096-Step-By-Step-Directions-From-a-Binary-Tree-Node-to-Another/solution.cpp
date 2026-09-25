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
    TreeNode* LCA(TreeNode* root, int p, int q) {
        if(!root) return NULL;
        if(root->val == p || root->val == q) return root;

        TreeNode* leftn = LCA(root->left , p, q);
        TreeNode* rightn = LCA(root->right , p ,q);
        
        if(leftn && rightn) return root;
        if(leftn) return leftn;
        return rightn;
    }
    bool findpath(TreeNode*node , int p, string &s){
        if(!node) return false;
        if(node->val == p) return true;
        s.push_back('L');
        if(findpath(node->left , p, s) == true){
            return true;
        }
        s.pop_back();
        s.push_back('R');
        if(findpath(node->right , p ,s) == true) return true;
        s.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int p, int q) {
        TreeNode* lca = LCA(root , p, q);
        string lcatop = "";
        string lcatoq = "";

        findpath(lca , p , lcatop);
        findpath(lca, q, lcatoq);

        string res = "";
        for(int i = 0;i<lcatop.size(); i++){
            res.push_back('U');
        }

        res+= lcatoq;

        return res;
    }
};