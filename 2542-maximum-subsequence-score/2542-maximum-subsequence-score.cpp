class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>> mx;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mn;
        int n=nums1.size();
        for(int i=0;i<n;i++)mx.push({nums1[i],i});
        long long sum=0,ans=0;
        while(k--){
            auto& x=mx.top();
            sum+=x.first;
            mn.push({nums2[x.second],x.second});
            mx.pop();
        }
        ans=sum*mn.top().first;
        while(!mx.empty()){
            auto& x=mn.top();
            sum-=nums1[x.second];
            mn.pop();
            auto& xx=mx.top();
            sum+=xx.first;
            mn.push({nums2[xx.second],xx.second});
            mx.pop();
            ans=max(ans,sum*mn.top().first);
        }
        return ans;
    }
};