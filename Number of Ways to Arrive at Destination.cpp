class Solution {
public:
    int mod=1e9+7;
    long long int INF=1e12+1;
    int shortestpath(int n,vector<vector<pair<int,long long int>>> &g){
        vector<long long int> dis(n,INF);
        vector<int> ways(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long ,int>>,greater<pair<long long ,int>>> pq;
        pq.push({0,0});
        dis[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            int top=pq.top().second;
            long long dist=pq.top().first;
            pq.pop();
            for(pair<int,long long int> p:g[top]){
                if(dist+p.second==dis[p.first]){
                    ways[p.first]=(ways[p.first]%mod+ways[top]%mod)%mod;
                }
                else if(dist+p.second<dis[p.first]){
                    ways[p.first]=ways[top]%mod;
                    dis[p.first]=dist+p.second;
                    pq.push({dis[p.first],p.first});
                }
            }
        }
        //cout<<dis[n-1];
        return ways[n-1]%mod;
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long int>>> g(n);
        for(vector<int> temp:roads){
            g[temp[0]].push_back({temp[1],temp[2]});
            g[temp[1]].push_back({temp[0],temp[2]});
        }
        return shortestpath(n,g);
    }
};
