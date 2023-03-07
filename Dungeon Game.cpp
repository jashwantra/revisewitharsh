class Solution {
public:
    long long int INF=0-(1e9+23);
    bool valid(int i,int j,int m,int n){
        if(i<0||i>=m||j<0||j>=n)
            return false;
        return true;
    }
    long long func(int i,int j,vector<vector<int>>& dungeon,vector<vector<long long>>& dp){
        if(dp[i][j]!=INF)
            return dp[i][j];
        long long ans;
        if(valid(i+1,j,dungeon.size(),dungeon[0].size()) && valid(i,j+1,dungeon.size(),dungeon[0].size())){
            ans=min(func(i+1,j,dungeon,dp),func(i,j+1,dungeon,dp));
        }
        else if(valid(i+1,j,dungeon.size(),dungeon[0].size()))
            ans=func(i+1,j,dungeon,dp);
        else
            ans=func(i,j+1,dungeon,dp);
        if(ans<=1){
            if(dungeon[i][j]>=0)
                ans=1;
            else
                ans=abs(dungeon[i][j])+1;
        }
        else{
            if(dungeon[i][j]>=0){
                if(dungeon[i][j]-ans>=0)
                    ans=1;
                else
                    ans=ans-dungeon[i][j];
            }
            else
                ans=ans+abs(dungeon[i][j]);
        }
        return dp[i][j]=ans;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<long long>> dp(dungeon.size(),vector<long long>(dungeon[0].size(),INF));
        if(dungeon[dungeon.size()-1][dungeon[0].size()-1]>=0)
            dp[dungeon.size()-1][dungeon[0].size()-1]=1;
        else
            dp[dungeon.size()-1][dungeon[0].size()-1]=abs(dungeon[dungeon.size()-1][dungeon[0].size()-1])+1;
        func(0,0,dungeon,dp);
        for(int i=0;i<dungeon.size();i++){
            for(int j=0;j<dungeon[0].size();j++)
                cout<<dp[i][j]<<" ";
            cout<<"\n";
        }
        return func(0,0,dungeon,dp);
    }
};
