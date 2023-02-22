class Solution {
public:
    bool possible(int capacity,vector<int>&weights,int days){
        int day=1,wt=0;
        for(int i=0;i<weights.size();i++){
            wt+=weights[i];
            if(wt>capacity){
                day++;
                wt=weights[i];
            }
        }
        //cout<<capacity<<" "<<day<<"\n";
        if(day<=days)
            return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int i=*max_element(weights.begin(),weights.end()),j=1e8+1;
        while(i<j){
            int mid=i+(j-i)/2;
            if(i+1==j){
                if(possible(i,weights,days))
                    return i;
                return j;
            }
            if(possible(mid,weights,days)){
                //cout<<mid<<"\n";
                j=mid;
            }
            else
                i=mid;
        }
        return i;
    }
};
