class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int INF=1e5+5;
        int ans=INF;
        map<int,int> count,index;
        for(int i=0;i<cards.size();i++){
            if(count[cards[i]]>=1){
                ans=min(ans,i-index[cards[i]]+1);
                count[cards[i]]++;
                index[cards[i]]=i;
            }
            else{
                count[cards[i]]++;
                index[cards[i]]=i;
            }
        }
        if(ans==INF)
            return -1;
        return ans;
    }
};
