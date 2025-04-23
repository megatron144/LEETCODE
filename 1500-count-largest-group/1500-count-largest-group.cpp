class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> mpp;
        int maxi=1;
        for(int i=1;i<=n;i++){
            int tmp=i;
            int sum=0;
            while(tmp){
                sum+=(tmp%10);
                tmp/=10;
            }
            mpp[sum]++;
            maxi=max(maxi,mpp[sum]);
        }
        int cnt=0;
        for(auto x: mpp){
            if(x.second==maxi)cnt++;
        }
        return cnt;
    }
};