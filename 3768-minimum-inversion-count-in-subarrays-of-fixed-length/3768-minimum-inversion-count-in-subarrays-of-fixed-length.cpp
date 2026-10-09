#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
template<class T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
public:
    long long minInversionCount(vector<int>& nums, int k) {
        pbds<pair<int,long long>> st;
        int n=nums.size();
        long long ans=1e15,curr=0;
        for(int i=0;i<n;i++){
            if(i<k){
                curr+=st.size()-st.order_of_key({nums[i],1e18});
                st.insert({nums[i],i});
            }
            else{
                ans=min(ans,curr);
                curr-=st.order_of_key({nums[i-k],-1});
                st.erase({nums[i-k],i-k});
                curr+=st.size()-st.order_of_key({nums[i],1e18});
                st.insert({nums[i],i});
            }
        }
        ans=min(ans,curr);
        return ans;
    }
};