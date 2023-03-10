class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        vector<pair<int,int>> fruit;
        int curr=fruits[0],count=1,i;
        for(i=1;i<fruits.size();i++){
            if(fruits[i]==curr)
                count++;
            else{
                fruit.push_back({curr,count});
                curr=fruits[i];
                count=1;
            }
        }
        fruit.push_back({curr,count});
        if(fruit.size()==1 || fruit.size()==2)
            return fruits.size();
        int curra=fruit[0].first,currb=fruit[1].first;
        count=fruit[0].second+fruit[1].second;int ans=count;
        for(int i=2;i<fruit.size();i++){
            if(fruit[i].first==curra || fruit[i].first==currb){
                count+=fruit[i].second;
            }
            else{
                curra=fruit[i-1].first;
                currb=fruit[i].first;
                count=fruit[i-1].second+fruit[i].second;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};
