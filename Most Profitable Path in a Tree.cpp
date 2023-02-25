class Solution {
public:
    int ans=INT_MIN;
    void findpath(int index,int bob,vector<vector<int>>&g,vector<int> &p,vector<int> &vis,vector<int>&b){
        if(b.size()!=0)
            return ;
        if(index==bob){
            //p.push_back(bob);
            b=p;
            return;
        }
        vis[index]=true;
        
            for(int vertex:g[index]){
                if(vis[vertex]==0){
                    p.push_back(vertex);
                    findpath(vertex,bob,g,p,vis,b);
                    p.pop_back();
                }
                if(b.size()!=0)
                    return;
            }       
    }
    void dfs(int index,vector<vector<int>>&g,vector<int>&amount,int ic,vector<int>&vis){
        vis[index]=1;
        if(g[index].size()==1 && vis[g[index][0]]==1){
            ans=max(ans,ic+amount[index]);
            return ;
        }
        for(int vertex:g[index]){
            if(vis[vertex]==0){
                dfs(vertex,g,amount,amount[index]+ic,vis);
            }
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        vector<vector<int>> g(amount.size());
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(amount.size(),0);
        vector<int> bobpath,path;
        path.push_back(0);
        findpath(0,bob,g,path,vis,bobpath);
        //for(int it:bobpath)
            //cout<<it<<" ";
        //cout<<"\n";
        int i=0,j=bobpath.size()-1;
        while(i<=j){
            if(i==j){
                amount[bobpath[i]]/=2;
                break;
            }
            else
                amount[bobpath[j]]=0;
            i++;j--;
        }
        //for(int i:amount)
            //cout<<i<<" ";
        ans=INT_MIN;
        for(i=0;i<vis.size();i++)
            vis[i]=0;
        dfs(0,g,amount,0,vis);
        return ans;
    }
};
