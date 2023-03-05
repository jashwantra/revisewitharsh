class Solution {
public:
    int calcsteps(long long n,long long n1,long long n2){
        int steps=0;
        while(n1<=n){
            steps+=min(n+1,n2)-n1;
            n1*=10;
            n2*=10;
        }
        return steps;
    }
    int findKthNumber(int n, int k) {
        k--;
        int curr=1;
        while(k>0){
            int steps=calcsteps(n,curr,curr+1);
            if(steps<=k){
                k-=steps;
                curr++;
            }
            else{
                curr*=10;
                k--;
            }
        }
        return curr;
    }
};
