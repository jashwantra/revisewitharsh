class Solution {
public:
    bool consistent(vector<vector<int>>&statements,int num){
        vector<int> good(statements.size(),0);
        for(int i=0;i<statements.size();i++){
            if((num&(1<<i))>0)
                good[i]=1;
        }
        for(int i=0;i<statements.size();i++){
            if(good[i]==true){
                for(int j=0;j<statements.size();j++){
                    if(statements[i][j]==2)
                        continue;
                    if(statements[i][j]==0){
                        if(good[j]==1)
                            return false;
                    }
                    else{
                        if(good[j]==0)
                            return false;
                    }
                }
            }
        }
        return true;
    }
    int maximumGood(vector<vector<int>>& statements) {
        int num=(1<<statements.size())-1;
        int ans=0;
        while(num>=0){
            if(consistent(statements,num)){
                ans=max(__builtin_popcount(num),ans);
            }
            num--;
        }
        return ans;
    }
};
