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
    void dfs(TreeNode* root,int cd,int &md,vector<int> &ans){
        if(root==NULL)return;
        if(cd>md){
            ans.push_back(root->val);
            md=cd;
        }
        dfs(root->right,cd+1,md,ans);
        dfs(root->left,cd+1,md,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int cd=0,md=-1;
        dfs(root,cd,md,ans);
        return ans;
    }
};