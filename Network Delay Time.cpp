class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int INF=1e5+5;
        vector<int> dis(n,INF),vis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<vector<pair<int,int>>> g(n);
        for(int i=0;i<times.size();i++){
            g[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }
        pq.push({0,k-1});
        vis[k-1]=1;
        dis[k-1]=0;
        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();
            //if(vis[u]==1)
                //continue;
            vis[u]=1;
            //pair<int,int> :: iterator it;
            for(auto it:g[u]){
                if(vis[(it).first]==1)
                    continue;
                if(dis[u]+(it).second<dis[(it).first]){
                    dis[(it).first]=dis[u]+(it).second;
                    pq.push({dis[(it).first],(it).first});
                }
            }
        }
        int ans=INT_MIN;
        for(int i:dis){
            if(i==INF)
                return -1;
            ans=max(i,ans);
        }
        return ans;
    }
};
