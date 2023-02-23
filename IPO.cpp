class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> pro;
        for(int i=0;i<profits.size();i++)
            pro.push_back({capital[i],profits[i]});
        sort(pro.begin(),pro.end());
        priority_queue<int> pq;
        int j=0;
        for(int i=0;i<k;i++){
            while(j<profits.size() && pro[j].first<=w){
                pq.push(pro[j].second);
                j++;
            }
            if(pq.empty())
                break;
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};
