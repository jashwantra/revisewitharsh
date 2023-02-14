class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]==temp[i])
                i++;
            if(nums[j]==temp[j])
                j--;
            if(nums[i]!=temp[i] && nums[j]!=temp[j])
                break;
        }
        if(j-i>0)
            return j-i+1;
        else
            return 0;
    }
};
