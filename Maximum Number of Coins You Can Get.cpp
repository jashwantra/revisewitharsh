class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int k=piles.size()/3,i=piles.size()-2,ans=0;
        while(k--){
            ans+=piles[i];
            i-=2;
        }
        return ans;
    }
};
