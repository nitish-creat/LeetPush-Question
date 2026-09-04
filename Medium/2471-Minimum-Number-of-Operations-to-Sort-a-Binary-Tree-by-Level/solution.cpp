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

    int check(vector<int>&arr){
        vector<pair<int,int>> temp;
        int count = 0;
        for(int i = 0; i<arr.size();i++){
            temp.push_back({arr[i] , i});
        }
        sort(temp.begin() , temp.end());
        for(int i = 0;i<temp.size(); i++){
            pair<int,int> p = temp[i];
            int ind = p.second;

            if(i != ind){
                count++;
                swap(temp[i] , temp[ind]);
                i--;
            }
        }

        return count;
    }
    int minimumOperations(TreeNode* root) {
        int count = 0;
        if(!root) return count;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                level.push_back(node->val);
            }

            count += check(level);
        }

        return count;
    }
};