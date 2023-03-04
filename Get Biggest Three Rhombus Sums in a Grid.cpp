class Solution {
public:
    int func(int I,int J,int k,vector<vector<int>>&grid){
        int ans=grid[I][J]+grid[I+2*k][J];
        int i=I+1,j=J;
        for(int l=1;l<=k;l++){
            ans+=grid[i][j-l]+grid[i][j+l];
            i++;
        }
        for(int l=k-1;l>=1;l--){
            ans+=grid[i][j-l]+grid[i][j+l];
            i++;
        }
        return ans;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int> st;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                st.insert(grid[i][j]);
                int K=min(min(j,(int)grid[0].size()-1-j),((int)grid.size()-1-i)/2);
                for(int k=1;k<=K;k++)
                    st.insert(func(i,j,k,grid));
            }
        }
        vector<int>v;
        for(auto it: st){
            v.push_back(it);
        }
        reverse(v.begin(), v.end());
        vector<int>ans;
        if(v.size()<3){return v;}
        for(int i=0; i<3; i++){ans.push_back(v[i]);}
        return ans;
    }
};
