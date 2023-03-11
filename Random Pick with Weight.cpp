class Solution {
public:
    vector<int> pre;
    Solution(vector<int>& w) {
        int gc=w[0];
        for(int i=1;i<w.size();i++)
            gc=__gcd(gc,w[i]);
        for(int i=0;i<w.size();i++)
            w[i]/=gc; 
        pre.push_back(w[0]);
        int x=w[0];
        for(int i=1;i<w.size();i++){
            pre.push_back(x+w[i]);
            x+=w[i];
        }  
    }
    
    int pickIndex() {
        int x=random()%pre[pre.size()-1];
        int ans=upper_bound(pre.begin(),pre.end(),x)-pre.begin();
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
