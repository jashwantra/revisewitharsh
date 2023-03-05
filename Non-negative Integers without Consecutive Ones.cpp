class Solution {
public:
    int findIntegers(int n) {
        vector<int> dp(32),dpzero(32),dpone(32);
        dpzero[0]=1;dp[0]=1;dpone[0]=0;
        for(int i=1;i<32;i++){
            dpone[i]=dpzero[i-1];
            dpzero[i]=dpzero[i-1]+dpone[i-1];
            dp[i]=dpzero[i]+dpone[i];
        }
        int ans=0,lastbit=-1;
        for(int k=30;k>=0;k--){
            int bit=(n>>k)&1;
            if(bit==1){
                ans+=dp[k];
                if(lastbit==1)
                    return ans;
            }
            lastbit=bit;
        }
        return ans+1;
    }
};
