class Solution {
public:
    long long summ(vector<vector<int>>&matrix){
        long long int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans+=abs(matrix[i][j]);
            }
        }
        return ans;
    }
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int negs=0,z=0;
        for(vector<int> x:matrix)
            for(int y:x)
                if(y==0){
                    z++;
                    break;
                }
                else if(y<0)
                    negs++;
        if(z>=1 || negs%2==0)
            return summ(matrix);
        int r=0,c=0;
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[i].size();j++)
                if(abs(matrix[i][j])<abs(matrix[r][c])){
                    r=i;
                    c=j;
                }
        long long int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(i==r && j==c)
                    ans-=abs(matrix[i][j]);
                else
                    ans+=abs(matrix[i][j]);
            }
        }
        return ans;
    }
};
