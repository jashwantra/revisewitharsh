class Solution {
public:
    bool palindrome(string x){
        int i=0,j=x.length()-1;
        while(i<j){
            if(x[i]!=x[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    bool isStrictlyPalindromic(int N) {
        for(int i=2;i<=N-2;i++){
            string temp="";
            int n=N;
            while(n!=0){
                temp+=('0'+n%i);
                n/=i;
            }
            if(palindrome(temp)==false)
                return false;
        }
        return true;
    }
};
