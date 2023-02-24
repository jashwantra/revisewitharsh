class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int INF=INT_MAX;
        queue<vector<int>> q;
        vector<vector<pair<int,int>>> g(n);
        for(int i=0;i<flights.size();i++)
            g[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        q.push({-1,src,0});
        vector<int> dis(n,INF);
        dis[src]=0;
        while(!q.empty()){
            int stops=q.front()[0],u=q.front()[1],disN=q.front()[2];
            q.pop();
            if(stops<k){
                for(int i=0;i<g[u].size();i++){
                    int v=g[u][i].first,w=g[u][i].second;
                    if(disN+w<dis[v]){
                        dis[v]=disN+w;
                        q.push({stops+1,v,dis[v]});
                        //stops[v]=stop+1;
                    }
                }
            }
        }
        if(dis[dst]!=INF)
            return dis[dst];
        return -1;
    }
};
