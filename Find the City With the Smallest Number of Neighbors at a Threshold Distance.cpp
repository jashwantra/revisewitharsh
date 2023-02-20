class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        long long int INF=INT_MAX;
        vector<vector<long long>> d(n,vector<long long>(n,INF));
        for(vector<int> edge:edges){
            d[edge[0]][edge[1]]=edge[2];
            d[edge[1]][edge[0]]=edge[2];
        }
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(i!=j && d[i][k]!=INF && d[k][j]!=INF)
                        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        vector<int> x(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<d[i][j]<<" ";
                if(d[i][j]<=distanceThreshold){
                    x[i]++;
                }
            }
            cout<<"\n";
        }
        int y=n;
        for(int i:x){
            cout<<i<<" ";
            y=min(y,i);
        }
        for(int i=n-1;i>=0;i--)
            if(x[i]==y)
                return i;
        return 0;
    }
};
