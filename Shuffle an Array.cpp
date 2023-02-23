class Solution {
public:
    vector<int> num;
    Solution(vector<int>& nums) {
        num=nums;
    }
    
    vector<int> reset() {
        return num;
    }
    
    vector<int> shuffle() {
        vector<int> shuff=num;
        int left=num.size();
        for(int i=num.size()-1;i>=1;i--){
            int j=rand()%left;
            swap(shuff[i],shuff[j]);
            left--;
        }
        return shuff;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
