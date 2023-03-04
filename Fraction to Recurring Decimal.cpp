class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long int num=1LL*numerator,denom=1LL*denominator,rem=0,count=0;
        if(num==0 || denom==0)
            return "0";
        string ans="";
        if(num<0 && denom<0){
            num=0-num;
            denom=0-denom;
        }
        else if(num<0 || denom<0){
            ans+="-";
            num=abs(num-0);
            denom=abs(denom-0);
        }
        unordered_map<long long int,int> mp;
        ans+=to_string(num/denom);
        num=num%denom;
        if(num==0)
            return ans;
        ans+=".";
        mp[num]++;
        num=num*10;
        while(num>0){
            if(count>=1)
                count++;
            ans+=to_string(num/denom);
            num=num%denom;
            if(num==rem)
                break;
            if(count==0 && mp[num]>0){
                rem=num;
                count=1;
            }
            mp[num]++;
            num*=10;
            //mp[num]++;
        }
        if(rem!=0){
        count--;
        int x=2*count;
        stack<char> st;
        while(x--){
            st.push(ans[ans.length()-1]);
            ans.pop_back();
        }
        ans+="(";
        while(count--){
            ans+=st.top();
            st.pop();
        }
        ans+=")";
        }
        return ans;
    }
};
