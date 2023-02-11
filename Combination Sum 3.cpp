class Solution {
public:
    void func(int k,int target,vector<int> &x,vector<vector<int>> &result,unordered_map<int,int> &mp){
        if(k==0 && target==0){
            result.push_back(x);
            return ;
        }
        if(k==0)
            return;
        int st;
        if(x.size()==0)
            st=1;
        else
            st=x[x.size()-1];
        for(int i=st;i<=9;i++){
            if(target-i>=0){
                if(mp[i]==false){
                    x.push_back(i);
                    mp[i]=true;
                    func(k-1,target-i,x,result,mp);
                    x.pop_back();
                    mp[i]=false;
                }
            }
            else
                break;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        unordered_map<int,int> mp;
        vector<vector<int>> ans;
        vector<int> temp;
        func(k,n,temp,ans,mp);
        return ans;
    }
};
