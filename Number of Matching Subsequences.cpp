class Solution {
public:
    string substring(string x){
        string ans="";
        for(int i=1;i<x.length();i++)
            ans+=x[i];
        return ans;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,bool> p;
        unordered_map<char,queue<string>> count;
        int ans=0;
        for(char a:s)
            p[a]=true;
        for(string x:words){
            if(p.find(x[0])!=p.end())
                count[x[0]].push(x);
        }
        for(int i=0;i<s.length();i++){
            string temp;
            if(count.find(s[i])!=count.end() && count[s[i]].size()>0){
                int l=count[s[i]].size();
                while(l--){
                    string x=count[s[i]].front();
                    count[s[i]].pop();
                    temp=substring(x);
                    if(temp.length()==0)
                        ans++;
                    else if(p.find(temp[0])!=p.end()){
                        count[temp[0]].push(temp);
                    }
                }
            }
        }
        return ans;
    }
};
