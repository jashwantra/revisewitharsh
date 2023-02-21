class Solution {
public:
    vector<int> dx={-1,0,1,0},dy={0,1,0,-1};
    bool valid(int i,int j,int m,int n){
        if(i<0||i>=m||j<0||j>=n)
            return false;
        return true;
    }
    int func(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&area,vector<vector<bool>>&vis){
        vis[i][j]=true;
        if(area[i][j]!=-1)
            return area[i][j];
        int ans=1;
        for(int k=0;k<4;k++){
            int X=i+dx[k],Y=j+dy[k];
            if(valid(X,Y,grid.size(),grid[0].size())&&grid[X][Y]==1&&vis[X][Y]==false)
                ans+=func(X,Y,grid,area,vis);
        }
        return area[i][j]=ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> area(grid.size(),vector<int>(grid[0].size(),-1));
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)
                    ans=max(ans,func(i,j,grid,area,visited));
            }
        }
        return ans;
    }
};
