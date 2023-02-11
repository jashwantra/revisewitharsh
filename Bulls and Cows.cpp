class Solution {
public:
    string getHint(string secret, string guess) {
        int x=0,y=0;
        string a="",b="";
        for(int i=0;i<secret.length();i++)
            if(secret[i]==guess[i])
                x++;
            else{
                a+=secret[i];
                b+=guess[i];
            }
        unordered_map<char,int> mp;
        for(int i=0;i<a.length();i++)
            mp[a[i]]++;
        
        for(int i=0;i<b.length();i++){
            if(mp[b[i]]>0){
                y++;
                mp[b[i]]--;
            }
        }
        return to_string(x)+"A"+to_string(y)+"B";
    }
};
