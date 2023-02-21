class Solution {
public:
    string customSortString(string order, string s) {
        string ans="";
        unordered_map<char,int> ord,ss;
        for(char a:order)
            ord[a]++;
        for(char a:s){
            if(ord.find(a)==ord.end())
                ans+=a;
            else
                ss[a]++;
        }
        for(char a:order){
            int k=ss[a];
            while(k--)
                ans+=a;
        }
        return ans;
    }
};
