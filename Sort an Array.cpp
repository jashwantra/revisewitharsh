class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        int mn=*min_element(nums.begin(),nums.end());
        int range=mx-mn+1;
        vector<int> count(range,0),output;
        for(int i:nums)
            count[i-mn]++;
        for(int i=0;i<count.size();i++){
            while(count[i]--)
                output.push_back(i+mn);
        }
        return output;
    }
};
