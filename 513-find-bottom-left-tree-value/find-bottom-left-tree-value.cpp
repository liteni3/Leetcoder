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
    void dfs(TreeNode* root,int cd,int &md,int &ans){
        if(root==NULL)return;
        if(cd>md){
            ans=root->val;
            md=cd;
        }
        dfs(root->left,cd+1,md,ans);
        dfs(root->right,cd+1,md,ans);

    }
    int findBottomLeftValue(TreeNode* root) {
        int cd=0;
        int md=-1;
        int ans;
        dfs(root,cd,md,ans);
        return ans;

    }
};