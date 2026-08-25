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
    bool helper(long long int left,long long int right,TreeNode* root){
        if(root==nullptr)return true;
        if(root->val <= left || root->val >= right)return false;
        return(helper(left,root->val,root->left) && helper(root->val,right,root->right));
    }
    bool isValidBST(TreeNode* root) {
        //Simple do the inorder traversal while maintaining the range
        long long int left=-1e18;
        long long int right=1e18;
        return helper(left,right,root); 
    }
};