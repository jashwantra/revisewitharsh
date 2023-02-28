class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<vector<int>> co;
        int a=-1,b=-1,c=-1;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='a')
                a=i;
            else if(s[i]=='b')
                b=i;
            else
                c=i;
            co.push_back({a,b,c});
        }
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(co[i][0]==-1 || co[i][1]==-1 || co[i][2]==-1)
                continue;
            int k=max(co[i][0],max(co[i][1],co[i][2]));
            ans+=s.length()-k;
        }
        return ans;
    }
};
