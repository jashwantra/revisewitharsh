class Solution {
public:
    vector<int> dx={-2,-2,-1,1,2,2,-1,1},dy={-1,1,2,2,-1,1,-2,-2};
    int valid(int i,int j,int n){
        if(i<0||i>=n||j<0||j>=n)
            return 0;
        return 1;
    }
    double func(int n,int k,int row,int column,map<vector<int>,double> &dp){
        if(k==1)
            return dp[{row,column,1}];
        if(dp.find({row,column,k})!=dp.end())
            return dp[{row,column,k}];
        double ans=(double)0;
        for(int i=0;i<8;i++){
            int X=row+dx[i],Y=column+dy[i];
            if(valid(X,Y,n)){
                ans=ans+func(n,k-1,X,Y,dp)/(double)8;
            }
        }
        return dp[{row,column,k}]=ans;
    }
    double knightProbability(int n, int K, int row, int column) {
        if(K==0)
            return (double)1;
        if(n==1)
            return (double)0;
        map<vector<int>,double> dp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int p=0;
                for(int k=0;k<8;k++){
                    int X=i+dx[k],Y=j+dy[k];
                    if(valid(X,Y,n))
                        p++;
                }
                dp[{i,j,1}]=p/(double)8.0;
            }
        }
        return func(n,K,row,column,dp);
    }
};
