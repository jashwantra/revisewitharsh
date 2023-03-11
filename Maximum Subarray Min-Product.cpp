class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        vector<int> left(nums.size()),right(nums.size());
        vector<long long int> sum(nums.size());
        stack<int> st,st1;
        left[0]=-1;
        st.push(0);
        for(int i=1;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]>=nums[i])
                st.pop();
            if(st.empty())
                left[i]=-1;
            else
                left[i]=st.top();
            st.push(i);
        }
        right[nums.size()-1]=nums.size();
        st1.push(nums.size()-1);
        for(int i=nums.size()-2;i>=0;i--){
            while(!st1.empty() && nums[st1.top()]>=nums[i])
                st1.pop();
            if(st1.empty())
                right[i]=nums.size();
            else
                right[i]=st1.top();
            st1.push(i);
        }
        sum[0]=nums[0];
        for(int i=1;i<nums.size();i++)
            sum[i]=sum[i-1]+nums[i];
        int count=0;
        for(int i=0;i<nums.size();i++)
            if(sum[i]<0)
                count++;
            //cout<<sum[i]<<" ";
        long long int ans=INT_MIN,mod=1e9+7;
        for(int i=0;i<nums.size();i++){
            int l=left[i]+1,r=right[i]-1;
            long long int s;
            if(l>0)
                s=sum[r]-sum[l-1];
            else
                s=sum[r];
            ans=max(ans,s*nums[i]);
            //cout<<ans<<" ";
            //if(ans<0)
                //count++;
        }
        //cout<<count;
        //cout<<sum[nums.size()-1];
        cout<<ans;
        return ans%mod;
    }
};
