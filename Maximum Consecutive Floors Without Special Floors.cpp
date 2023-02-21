class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int ans=0;
        vector<int> x;
        x.push_back(bottom-1);
        for(int i:special)
            x.push_back(i);
        x.push_back(top+1);
        sort(x.begin(),x.end());
        for(int i=1;i<x.size();i++)
            ans=max(ans,x[i]-x[i-1]-1);
        return ans;
    }
};
