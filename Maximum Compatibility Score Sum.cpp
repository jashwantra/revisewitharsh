class Solution {
public:
    int ans=INT_MIN;
    int calcscore(vector<int> x,vector<int> y){
        int ans=0;
        for(int i=0;i<x.size();i++)
            ans+=(x[i]==y[i]);
        return ans;
    }
    void func(int index,int score,vector<bool>&mark, vector<vector<int>>&students,vector<vector<int>>&mentors){
        if(index>=students.size()){
            ans=max(ans,score);
            return ;
        }
        for(int i=0;i<mentors.size();i++){
            if(mark[i]==false){
                mark[i]=true;
                func(index+1,score+calcscore(students[index],mentors[i]),mark,students,mentors);
                mark[i]=false;
            }
        }
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vector<bool> mark(students.size(),false);
        func(0,0,mark,students,mentors);
        return ans;
    }
};
