class Solution {
public:
    bool valid(int i,int j,int m,int n){
        if(i<0||i>=m||j<0||j>=n)
            return false;
        return true;
    }
    bool possible(vector<vector<int>>&grid,int t){
        if(grid[0][0]>t)
            return false;
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        vector<int> dx={-1,1,0,0},dy={0,0,-1,1};
        visited[0][0]=1;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            int x=q.front().first,y=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int X=x+dx[k],Y=y+dy[k];
                if(valid(X,Y,grid.size(),grid[0].size()) && !visited[X][Y]){
                    if(grid[X][Y]<=t){
                        visited[X][Y]=1;
                        q.push({X,Y});
                    }
                }
            }
        }
        return visited[grid.size()-1][grid[0].size()-1];
    }
    int swimInWater(vector<vector<int>>& grid) {
        int left=INT_MAX,right=INT_MIN,mid;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                left=min(left,grid[i][j]);
                right=max(right,grid[i][j]);
            }
        }
        while(left<right){
            if(left+1==right){
                if(!possible(grid,left))
                    left=right;
                break;
            }
            mid=left+(right-left)/2;
            if(possible(grid,mid))
                right=mid;
            else
                left=mid+1;
        }
        return left;
    }
};
