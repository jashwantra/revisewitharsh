class Solution {
public:
    bool valid(int i,int j,int m,int n){
        if(i<0||i>=m||j<0||j>=n)
            return false;
        return true;
    }
    int func(int i,int j,int k,vector<vector<int>>&mat){
        int ans=0;
        for(int in=i-k;in<=i+k;in++){
            for(int jn=j-k;jn<=j+k;jn++){
                if(valid(in,jn,mat.size(),mat[0].size()))
                    ans+=mat[in][jn];
            }
        }
        return ans;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size()));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                ans[i][j]=func(i,j,k,mat);
            }
        }
        return ans;
    }
};
