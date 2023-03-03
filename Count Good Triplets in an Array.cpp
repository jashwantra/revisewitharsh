#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set_less;
typedef tree<int, null_type, greater<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set_greater;
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        ordered_set_less left;
        ordered_set_greater right;
        unordered_map<int,int> pos;
        vector<int> lefta(nums1.size(),0),righta(nums2.size(),0);
        for(int i=0;i<nums2.size();i++)
            pos[nums2[i]]=i;
        left.insert(pos[nums1[0]]);
        for(int i=1;i<nums1.size();i++){
            lefta[i]=left.order_of_key(pos[nums1[i]]);
            left.insert(pos[nums1[i]]);
        }
        right.insert(pos[nums1[nums1.size()-1]]);
        for(int i=nums1.size()-2;i>=0;i--){
            righta[i]=right.order_of_key(pos[nums1[i]]);
            right.insert(pos[nums1[i]]);
        }
        long long int ans=0;
        for(int i=1;i<nums1.size()-1;i++)
            ans+=1LL*lefta[i]*righta[i];
        return ans;
    }
};
