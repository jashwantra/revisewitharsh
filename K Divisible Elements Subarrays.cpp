class Solution {
public:
    long long int h=229,mod=INT_MAX;
    long long int calchash(int start,int end,vector<long long>&hash,vector<long long>&power){
        if(start==0)
            return hash[end];
        return (hash[end]-(hash[start-1]*power[end-start+1]%mod)%mod+mod)%mod;
    }
    int countDistinct(vector<int>& nums, int k, int p) {
        vector<long long int> hashing(nums.size(),0),power(nums.size(),1);
        hashing[0]=nums[0]%mod;
        for(int i=1;i<nums.size();i++)
            power[i]=(power[i-1]*h)%mod;
        for(int i=1;i<nums.size();i++)
            hashing[i]=(hashing[i-1]*h+nums[i])%mod;
        vector<int> prefix(nums.size());
        set<long long int> st;
        if(nums[0]%p==0)
            prefix[0]=1;
        else
            prefix[0]=0;
        for(int i=1;i<nums.size();i++)
            prefix[i]=prefix[i-1]+(nums[i]%p==0);
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                if(i==0){
                    if(prefix[j]<=k){
                        st.insert(hashing[j]);
                    }
                }
                else if(prefix[j]-prefix[i-1]<=k){
                    st.insert(calchash(i,j,hashing,power));
                }
            }
        }
        return st.size();
    }
};
