vector<long long> v[2];
int init = [](){
    for(int i=1;i<100000;i++){
        string s=to_string(i),r=s;
        reverse(r.begin(),r.end());
        long long p1=stoll(s.substr(0,s.size()-1)+r),p2=stoll(s+r);
        if(p1<1e9)v[p1&1].push_back(p1);
        if(p2<1e9)v[p2&1].push_back(p2);
    }
    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end());
    return 0;
}();
class Solution {    
public:
    long long minOperations(vector<int>& nums) {
        long long cnt=0;
        for(auto x: nums){
            auto& arr=v[x&1];
            int idx=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
            if(idx>=arr.size())idx=arr.size()-1;
            int a=abs(x-arr[idx]),b=idx>0?abs(x-arr[idx-1]):1e9;
            cnt+=min(a,b)/2;
        }
        return cnt;
    }
};