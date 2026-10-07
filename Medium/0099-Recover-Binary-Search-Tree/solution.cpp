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
    void inorder(TreeNode* root, vector<int> &arr){
        if(!root) return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }

    void solve(TreeNode* root, vector<int>&arr,int&ind){
        if(!root) return;
        solve(root->left, arr, ind);
        if(root->val != arr[ind]) root->val = arr[ind];
        ind++;
        solve(root->right,arr,ind);
    }
    void recoverTree(TreeNode* root) {
        vector<int> arr;
        inorder(root , arr);
        sort(arr.begin(),arr.end());
        int ind = 0;
        solve(root , arr,ind);
    }
};