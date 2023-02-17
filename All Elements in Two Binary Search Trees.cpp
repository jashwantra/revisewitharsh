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
    void func(TreeNode* root,vector<int>&a){
        if(root==NULL)
            return;
        func(root->left,a);
        a.push_back(root->val);
        func(root->right,a);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> x,y,ans;
        func(root1,x);
        func(root2,y);
        for(int i:x)
            cout<<i<<" ";
        cout<<"\n";
        for(int j:y)
            cout<<j<<" ";
        int i=0,j=0;
        while(i<x.size() && j<y.size()){
            if(x[i]<=y[j]){
                ans.push_back(x[i]);
                i++;
            }
            else{
                ans.push_back(y[j]);
                j++;
            }
        }
        while(i<x.size()){
            ans.push_back(x[i]);
            i++;
        }
        while(j<y.size()){
            ans.push_back(y[j]);
            j++;
        }
        return ans;
    }
};
