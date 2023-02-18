class Solution {
public:
    int magicalString(int n) {
        if(n<=3)
            return 1;
        string x="122";
        int i=2,ans=0;
        while(x.size()<n){
            if(x[i]=='1'){
                if(x[x.size()-1]=='1')
                    x+='2';
                else
                    x+='1';
            }
            else{
                if(x[x.size()-1]=='1')
                    x+="22";
                else
                    x+="11";
            }
            i++;
        }
        //cout<<x;
        for(i=0;i<n;i++)
            if(x[i]=='1')
                ans++;
        return ans;
    }
};
