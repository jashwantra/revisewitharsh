class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int> mp;
        int count=0;
        for(vector<int> a:rectangles){
            mp[{a[0],a[1]}]++;
            mp[{a[0],a[3]}]--;
            mp[{a[2],a[3]}]++;
            mp[{a[2],a[1]}]--;
        }
        for(auto it:mp){
            if(it.second==1||it.second==-1)
                count++;
            else if(it.second!=0)
                return false;
        }
        if(count==4)
            return true;
        return false;
    }
};
