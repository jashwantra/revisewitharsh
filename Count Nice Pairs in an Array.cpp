class Solution {
public:
    int mod=1e9+7;
    int reverse(int a){
        int ans=0;
        while(a!=0){
            ans=ans*10+a%10;
            a/=10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        map<int,int> count;
        long long int ans=0;
        for(int i:nums)
            count[i-reverse(i)]++;
        for(auto it:count)
            ans=(ans+1LL*it.second*(it.second-1)/2)%mod;
        return ans;
    }
};
