class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        vector<vector<string>> ans;
        unordered_map<string,long long int> mp;//creators[i],sum of views
        unordered_map<string,string> mp2;//<creators[i], ids[i]
        unordered_map<string,int> mp3;//ids[i] views[i]
        for(int i=0;i<creators.size();i++){
            mp[creators[i]]+=views[i];
            mp3[ids[i]]=max(mp3[ids[i]],views[i]);
        }
        for(int i=0;i<creators.size();i++){
            if(mp2.find(creators[i])==mp2.end())
                mp2[creators[i]]=ids[i];
            else{
                if(views[i]>mp3[mp2[creators[i]]]){
                    mp2[creators[i]]=ids[i];
                }
                if(views[i]==mp3[mp2[creators[i]]]){
                    mp2[creators[i]]=min(mp2[creators[i]],ids[i]);
                }
            }
        }
        long long int maxview=INT_MIN;
        for(auto it:mp)
            maxview=max(maxview,it.second);
        for(auto it:mp){
            if(it.second==maxview){
                ans.push_back({it.first,mp2[it.first]});
            }
        }
        return ans;
    }
};
