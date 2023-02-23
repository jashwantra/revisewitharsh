class Solution {
public:
    bool valid(string s){
        if(s.length()==0)
            return false;
        if(s[0]=='0'){
            if(s.length()==1)
                return true;
            return false;
        }
        stringstream ss(s);
        int a;
        ss>>a;
        if(0<=a && a<=255)
            return true;
        return false;
    }
    void func(int i,int k,string s,vector<string>&ans,string &os){
        string temp="";
        if(k==4){
            for(int in=i;in<os.length();in++)
                temp+=os[in];
            if(valid(temp)){
                s+=temp;
                ans.push_back(s);
                //cout<<s<<" "<<temp<<"\n";
                return ;
            }
            else
                return ;
        }
        temp+=os[i];
        if(valid(temp))
            func(i+1,k+1,s+temp+".",ans,os);  
        temp+=os[i+1];
        if(valid(temp))
            func(i+2,k+1,s+temp+".",ans,os);
        temp+=os[i+2];
        if(valid(temp))
            func(i+3,k+1,s+temp+".",ans,os);
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        func(0,1,"",ans,s);
        return ans;
    }
};
