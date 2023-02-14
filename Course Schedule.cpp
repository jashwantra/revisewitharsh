class Solution {
public:
    bool func(int vertex,unordered_map<int,bool> &path,unordered_map<int,bool>&vis,vector<vector<int>> &g){
        if(vis[vertex]==true)
            return false;
        vis[vertex]=true;
        path[vertex]=true;
        for(int it:g[vertex]){
            if(path[it]==true){
                path[vertex]=false;
                return true;
            }
        }
        bool ans=false;
        for(int it:g[vertex]){
            if(vis[it]==false){
                ans=ans|func(it,path,vis,g);
            }
        }
        path[vertex]=false;
        return ans;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,bool> path,vis;
        vector<vector<int>> g(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            g[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;i++){
            if(vis[i]==false){
                if(func(i,path,vis,g)==true)
                    return false;
            }
        }
        return true;
    }
};
