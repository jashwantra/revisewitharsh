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
    pair<long long int,int> func(TreeNode* root,int & ans){
        if(root==NULL)
            return {0,0};
        pair<long long int,int> x=func(root->left,ans),y=func(root->right,ans);
        pair<long long int,int> z={(x.first+y.first+root->val),(x.second+y.second+1)};
        if(root->val==z.first/z.second)
            ans++;
        return z;
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        func(root,ans);
        return ans;
    }
};
