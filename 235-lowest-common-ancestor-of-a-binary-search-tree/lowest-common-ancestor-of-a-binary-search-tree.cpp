/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void inorder(TreeNode* root,int left,int right,TreeNode* &ans){
        //inorder
        if(root==NULL)return;
        if(root->val > left && root->val <right ){
            ans=root;
            return;
        } else {
            if(root->val == left || root->val ==right){
                ans=root;
                return;
            }
        }
        inorder(root->left,left,right,ans);
        inorder(root->right,left,right,ans);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
           TreeNode* ans=NULL;
           int left = min(p->val,q->val);
           int right=max(p->val,q->val);
           inorder(root,left,right,ans);
           return ans;
    }
};