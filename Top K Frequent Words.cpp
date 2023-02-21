bool func(pair<int,string> x,pair<int,string> y){
    if(x.first!=y.first)
        return x.first>y.first;
    return x.second<y.second;
}
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(string word : words)
            mp[word]++;
        vector<pair<int,string>> x;
        for(auto it:mp)
            x.push_back({it.second,it.first});
        sort(x.begin(),x.end(),func);
        //reverse(x.begin(),x.end());
        vector<string> ans;
        int i=0;
        while(k--){
            ans.push_back(x[i].second);
            i++;
        }
        return ans;
    }
};
