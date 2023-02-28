class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<=2)
            return points.size();
        int ans=2;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int tc=2;
                for(int k=0;k<points.size();k++){
                    if(k==i || k==j)
                        continue;
                    int area=points[i][0]*(points[j][1]-points[k][1])+points[j][0]*(points[k][1]-points[i][1])+points[k][0]*(points[i][1]-points[j][1]);
                    if(area==0)
                        tc++;
                }
                ans=max(ans,tc);
            }
        }
        return ans;
    }
};
