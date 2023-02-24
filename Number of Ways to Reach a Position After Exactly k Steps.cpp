class Solution {
public:
    int mod=1e9+7;
    int func(int index,int k,vector<vector<long long int>> &dp){
        if(k<0)
            return 0;
        if(dp[index][k]!=-1)
            return dp[index][k];
        return dp[index][k]=(func(index+1,k-1,dp)%mod+func(index-1,k-1,dp)%mod)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        startPos+=1000;
        endPos+=1000;
        if(endPos<startPos)
            swap(startPos,endPos);
        /*
        if(startPos==endPos){
            if(k==0)
                return 1;
            return 0;
        }
        */
        if((endPos-startPos)%2!=(k%2))
            return 0;
        vector<vector<long long int>> dp(4009,vector<long long int>(1001,-1));
        for(int i=endPos-k;i<=endPos+k;i++){
            dp[i][abs(endPos-i)]=1LL;
        }
        return func(startPos,k,dp);
    }
};
