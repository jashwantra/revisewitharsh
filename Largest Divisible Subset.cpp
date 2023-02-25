class Solution {
public:
    int func(int index,vector<int> &nums,vector<int> &dp){
        if(dp[index]!=-1)
            return dp[index];
        int ans=1;
        for(int i=index-1;i>=0;i--)
            if(nums[index]%nums[i]==0)
                ans=max(ans,1+func(i,nums,dp));
        return dp[index]=ans;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),-1);
        stack<int> st;
        int ans=1;
        for(int i=nums.size()-1;i>=0;i--)
            ans=max(ans,func(i,nums,dp));
        cout<<ans<<"\n";
        for(int i=nums.size()-1;i>=0;i--){
            if(dp[i]==ans){
                if(st.empty()){
                    st.push(nums[i]);
                    ans--;
                }
                else if(st.top()%nums[i]==0){
                    st.push(nums[i]);
                    ans--;
                }
            }
        }
        vector<int> ansx;
        while(!st.empty()){
            ansx.push_back(st.top());
            st.pop();
        }
        return ansx;
    }
};
