class Solution {
public:
    int mod=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long int> dp(n+1,0);
        dp[1]=1;
        long long int noofpeoplesharing=0,ans=0;
        for(int i=2;i<=n;i++){
            long long int noofnewpeoplesharing=dp[max(i-delay,0)];
            long int noofpeopleforgetting=dp[max(i-forget,0)];
            noofpeoplesharing=(noofpeoplesharing + noofnewpeoplesharing-noofpeopleforgetting+mod)%mod;
            dp[i]=noofpeoplesharing;
        }
        for(int i=n-forget+1;i<=n;i++)
            ans=(ans+dp[i])%mod;
        return ans;
    }
};
