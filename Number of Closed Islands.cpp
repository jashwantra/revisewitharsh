class Solution {
public:
    vector<int> dx={-1,0,1,0},dy={0,1,0,-1};
    bool validans(int i,int j,int m,int n){
        if(i==0||j==0||i==m-1||j==n-1)
            return false;
        return true;
    }
    bool valid(int i,int j,int m,int n){
        if(i<0||i>=m||j<0||j>=n)
            return false;
        return true;
    }
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&vis){
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int X=i+dx[k],Y=j+dy[k];
            if(valid(X,Y,grid.size(),grid[0].size()) && grid[i][j]==0 && !vis[X][Y])
                dfs(X,Y,grid,vis);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int ans=0;
        for(int j=0;j<n;j++){
            if(grid[0][j]==0 && !vis[0][j])
                dfs(0,j,grid,vis);
            if(grid[m-1][j]==0 && !vis[m-1][j])
                dfs(m-1,j,grid,vis);
        }
        for(int i=0;i<m;i++){
            if(grid[i][0]==0 && !vis[i][0])
                dfs(i,0,grid,vis);
            if(grid[i][n-1]==0 && !vis[i][n-1])
                dfs(i,n-1,grid,vis);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    //if(validans(i,j,m,n))
                    ans++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return ans;
    }
};
