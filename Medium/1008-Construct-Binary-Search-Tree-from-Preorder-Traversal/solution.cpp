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
    TreeNode* solve(vector<int>&pre , vector<int>&in , int start , int end,int&ind){
        if(start > end) return NULL;
        int rootval = pre[ind];
        int i = start;
        for(; i<=end ;i++){
            if(in[i] == rootval) break;
        }
        ind++;

        TreeNode* root = new TreeNode(rootval);
        root->left = solve(pre, in, start, i-1, ind);
        root->right = solve(pre , in, i+1 , end, ind);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin() , inorder.end());
        int ind = 0;
        int n = preorder.size();
        return solve(preorder , inorder, 0, n-1,ind);
    }
};