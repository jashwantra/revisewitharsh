class Solution {
public:
    void radixsort(vector<pair<string,int>> &nums,int k){
        vector<pair<string,int>> op(nums.size());
        int i;vector<int> count(10,0);
        for(i=0;i<nums.size();i++)
            count[nums[i].first[k-1]-'0']++;
        for(i=1;i<10;i++)
            count[i]+=count[i-1];
        for(i=nums.size()-1;i>=0;i--){
            op[count[nums[i].first[k-1]-'0']-1]=nums[i];
            count[nums[i].first[k-1]-'0']--;
        }
        for(i=0;i<nums.size();i++)
            nums[i]=op[i];
        /*
        vector<vector<pair<string,int>>> as(11);
        for(pair<string,int> x:nums){
            as[x.first[k-1]-'0'].push_back(x);
        }
        //vector<pair<string,int>> ans;
        int fd=0;
        for(vector<pair<string,int>> x:as){
            for(pair<string,int> y:x){
                nums[fd++]=y;
            }
        }
        */
        //nums=ans;
    }
    string reverse(string & x){
        string ans="";
        for(auto it=x.rbegin();it!=x.rend();it++)
            ans+=(*it);
        return ans;
    }
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> querie;
        vector<pair<string,int>> num;
        for(int i=0;i<nums.size();i++){
            num.push_back({reverse(nums[i]),i});
        }
        //for(pair<string,int>&p:num)
            //reverse(p.first.begin(),p.first.end());
        vector<int> ans(queries.size());
        int k=0;
        for(int i=0;i<queries.size();i++)
            querie.push_back({queries[i][1],queries[i][0],i});
        sort(querie.begin(),querie.end());
        for(int i=0;i<querie.size();i++){
            while(k<querie[i][0]){
                k++;
                radixsort(num,k);
            }
            ans[querie[i][2]]=num[querie[i][1]-1].second;
        }
        return ans;
    }
};
