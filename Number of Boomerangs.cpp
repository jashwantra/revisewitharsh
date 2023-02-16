class Solution {
public:
    long long int distance(int x1,int y1,int x2,int y2){
        return 1LL*(x1-x2)*(x1-x2)+1LL*(y1-y2)*(y1-y2);
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans=0;int n=points.size();
        unordered_map<int,int> distances;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                distances[distance(points[i][0],points[i][1],points[j][0],points[j][1])]++;
            }
            for(auto it:distances){
                ans+=it.second*(it.second-1);
            }
            distances.clear();
        }
        return ans;
    }
};
