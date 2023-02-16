class Solution {
public:
    int func(int i,int numArrows,vector<vector<int>> &dp,vector<int>&aliceArrows){
        if(numArrows<0)
            return INT_MIN;
        if(i==0){
            return 0;
        }
        if(dp[i][numArrows]!=-1)
            return dp[i][numArrows];
        return dp[i][numArrows]=max(func(i-1,numArrows,dp,aliceArrows), i+func(i-1,numArrows-aliceArrows[i]-1,dp,aliceArrows));
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<vector<int>> dp(12,vector<int>(numArrows+1,-1));
        vector<int> ans(12,0);
        int remainingArrows=numArrows;
        func(11,numArrows,dp,aliceArrows);
        for(int i=11;i>=1;i--){
            if(func(i,remainingArrows,dp,aliceArrows)!=func(i-1,remainingArrows,dp,aliceArrows)){
                ans[i]=aliceArrows[i]+1;
                remainingArrows-=ans[i];
            }
        }
        ans[0]=remainingArrows;
        return ans;
    }
};
