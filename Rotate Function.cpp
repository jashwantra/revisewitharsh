class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        vector<int> f(nums.size());
        for(int i=0;i<nums.size();i++)
            f[0]+=i*nums[i];
        for(int k=1;k<nums.size();k++){
            f[k]=f[k-1]+sum-n*nums[n-k];
        }
        int ans=INT_MIN;
        for(int it:f)
            ans=max(ans,it);
        return ans;
    }
};
