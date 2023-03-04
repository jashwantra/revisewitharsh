class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)
            return false;
        vector<int> left(nums.size(),0),right(nums.size(),nums.size()-1);
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[left[i-1]])
                left[i]=i;
            else
                left[i]=left[i-1];
        }
        for(int i=nums.size()-2;i>0;i--){
            if(nums[i]>nums[right[i+1]])
                right[i]=i;
            else
                right[i]=right[i+1];
        }
        for(int i=1;i<nums.size()-1;i++){
            if(nums[left[i-1]]<nums[i] && nums[i]<nums[right[i+1]])
                return true;
        }
        return false;
    }
};
