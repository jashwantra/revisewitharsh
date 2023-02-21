class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length()<=k)
            return false;
        set<string> st;
        for(int i=0;i<=s.length()-k;i++){
            string temp="";
            for(int j=i;j<i+k;j++){
                if(j==s.length())
                    break;
                temp+=s[j];
            }
            st.insert(temp);
        }
        int n=pow(2,k);
        if(st.size()==n)
            return true;
        return false;
    }
};
