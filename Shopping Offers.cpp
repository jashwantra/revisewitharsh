class Solution {
public:
    int dotpro(vector<int> &x,vector<int>&y){
        int ans=0;
        for(int i=0;i<x.size();i++)
            ans+=x[i]*y[i];
        return ans;
    }
    vector<int> minus(vector<int> &x,vector<int>&y){
        vector<int> ans(x.size());
        for(int i=0;i<x.size();i++)
            ans[i]=x[i]-y[i];
        return ans;
    }
    int func(vector<int> needs,vector<int>&price,vector<vector<int>>&special,map<vector<int>,int>&dp){
        bool f0=true,f1=false;
        for(int x:needs){
            if(x>0)
                f0=false;
            if(x<0)
                f1=true;
        }
        if(f1==true)
            return -1;
        if(f0==true)
            return 0;
        if(dp.find(needs)!=dp.end())
            return dp[needs];
        int ans=dotpro(price,needs);
        for(int i=0;i<special.size();i++){
            int x=func(minus(needs,special[i]),price,special,dp);
            if(x==-1)
                continue;
            ans=min(ans,x+special[i][needs.size()]);
        }
        return dp[needs]=ans;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        map<vector<int>,int> dp;
        return func(needs,price,special,dp);
    }
};
