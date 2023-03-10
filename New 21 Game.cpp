class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> prob(n+maxPts,0);
        double sum=0,x=1;
        for(int i=k;i<=n;i++){
            prob[i]=1;
            sum+=1;
        }
        for(int i=k-1;i>=0;i--){
            prob[i]=sum/maxPts;
            sum+=prob[i];
            sum-=prob[i+maxPts];
        }
        return min(x,prob[0]);
    }
};
