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
    void dfs(TreeNode* &ans, TreeNode* root, int val){
        if(root==nullptr)return ;
        if(root-> val == val){
            ans=root;
        }
        else if(root->val > val){
            dfs(ans,root->left,val);
        }
        else if(root->val < val){
            dfs(ans,root->right,val);
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans=nullptr;
        dfs(ans,root,val);
        return ans;
    }
};