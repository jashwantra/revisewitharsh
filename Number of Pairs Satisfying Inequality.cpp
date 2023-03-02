#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type,
             less<pair<int, int> >, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset;
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        ordered_multiset p;
        long long int ans=0;
        for(int i=0;i<nums1.size();i++){
            int x=nums1[i]-nums2[i]+diff;
            long long int pos=p.order_of_key({x,nums1.size()+1});
            p.insert({x-diff,i});
            ans+=pos;
        }
        return ans;
    }
};
