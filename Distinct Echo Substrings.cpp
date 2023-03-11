class Solution {
public:
    long long int h=256,mod=1e9+7;
    long long int calchash(int start,int end,vector<long long>&prefix,vector<long long>&power){
        if(start==0)
            return prefix[end];
        return (prefix[end]-(prefix[start-1]*power[end-start+1]%mod)%mod+mod)%mod;
    }
    int distinctEchoSubstrings(string text) {
        vector<long long int> prefix(text.size(),0),power(text.size(),1);
        set<long long int> st;
        for(int i=1;i<text.size();i++)
            power[i]=(power[i-1]*h)%mod;
        prefix[0]=text[0]-'a'+1;
        for(int i=1;i<text.size();i++)
            prefix[i]=((prefix[i-1]*h)%mod+(text[i]-'a'+1))%mod;
        //for(long long int i:prefix)
            //cout<<i<<" ";
        cout<<"\n";
        for(int l=1;l<=text.size()/2;l++){
            for(int i=0,j=i+l;j+l<=text.size();i++,j++){
                long long hash1=calchash(i,j-1,prefix,power);
                long long hash2=calchash(j,j+l-1,prefix,power);
                //cout<<i<<" "<<j-1<<" "<<j<<" "<<j+l-1<<" "<<hash1<<" "<<hash2<<"\n";
                if(hash1==hash2)
                    st.insert(hash1);
            }
        }
        return st.size();
    }
};
