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
    int func(TreeNode* root,int k,map<pair<TreeNode*,int>,int>&dp){
        if(root==NULL)
            return 0;
        if(dp.find({root,k})!=dp.end())
            return dp[{root,k}];
        if(k==1){
            int x=max(func(root->left,0,dp),func(root->left,1,dp));
            int y=max(func(root->right,0,dp),func(root->right,1,dp));
            return dp[{root,k}]=x+y;
        }
        else{
            int ans=root->val+func(root->left,1,dp)+func(root->right,1,dp);
            ans=max(ans,func(root->left,0,dp)+func(root->right,0,dp));
            return dp[{root,k}]=ans;
        }
    }
    int rob(TreeNode* root) {
        map<pair<TreeNode*,int>,int> dp;
        return max(func(root,0,dp),func(root,1,dp));
    }
};
