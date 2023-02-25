class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
        for(int i=nums1.size()-1;i>=0;i--){
            for(int j=nums2.size()-1;j>=0;j--){
                if(nums1[i]==nums2[j])
                    dp[i][j]=dp[i+1][j+1]+1;
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<nums1.size();i++)
            for(int j=0;j<nums2.size();j++)
                ans=max(ans,dp[i][j]);
        return ans;
    }
};
