class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime(right+1,true);
        prime[0]=false;prime[1]=false;
        for(int i=2;i*i<=right;i++){
            if(prime[i]==true){
                for(int j=i*i;j<=right;j+=i)
                    prime[j]=false;
            }
        }
        int i=left,num1=left,num2=right,temp1=-1,temp2=-1;
        while(i<=right){
            if(prime[i]==true){
                //num1=prime[i];
                temp1=i;
                i++;
                break;
            }
            i++;
        }
        while(i<=right){
            if(prime[i]==true){
                temp2=i;
                if(temp2-temp1<num2-num1){
                    num1=temp1;
                    num2=temp2;
                }
                temp1=temp2;
            }
            i++;
        }
        if(prime[num1]==false || prime[num2]==false)
            return {-1,-1};
        return {num1,num2};
    }
};
