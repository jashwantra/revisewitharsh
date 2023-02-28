class Solution {
public:
    long long int distance(vector<int> x,vector<int> y){
        return (1LL*x[0]-y[0])*(x[0]-y[0])+(1LL*x[1]-y[1])*(x[1]-y[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<long long int,int> mp;
        mp[distance(p1,p2)]++;
        mp[distance(p1,p3)]++;
        mp[distance(p1,p4)]++;
        mp[distance(p2,p3)]++;
        mp[distance(p2,p4)]++;
        mp[distance(p3,p4)]++;
        if(mp.size()==2){
            auto it=mp.begin();
            long long int x=(*it).first,xc=(*it).second;
            it++;
            long long int y=(*it).first,yc=(*it).second;
            if(x==2*y && xc==2 && yc==4)
                return true;
            else if(y==2*x && xc==4 && yc==2)
                return true;
            return false;
        }
        else
            return false;
    }
};
