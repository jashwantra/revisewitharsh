class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g=numsDivide[0];
        int ans=0;
        for(int i=1;i<numsDivide.size();i++)
            g=__gcd(g,numsDivide[i]);
        sort(nums.begin(),nums.end());
        for(int it:nums){
            if(g%it==0)
                break;
            ans++;
        }
        if(ans==nums.size())
            return -1;
        return ans;
    }
};
