class Solution {
public:
    int ans=INT_MIN;
    void func(int index,string &s ,set<string>& st){
        if(index==s.length()){
            int l=st.size();
            ans=max(ans,l);
            return; 
        }
        string temp="";
        for(int i=index;i<s.length();i++){
            temp+=s[i];
            if(st.find(temp)==st.end()){
                st.insert(temp);
                func(i+1,s,st);
                set<string> :: iterator it=st.find(temp);
                st.erase(temp);
            }
            else{
                func(i+1,s,st);
            }
        }
    }
    int maxUniqueSplit(string s) {
        set<string> st;
        func(0,s,st);
        return ans;
    }
};
