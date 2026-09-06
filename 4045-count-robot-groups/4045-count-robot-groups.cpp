class Solution {
public:
    int countGroups(vector<int>& pos, vector<int>& speed, int dis) {
        int n=speed.size(),curr=speed[n-1];
        int cnt=n;
        for(int i=n-1;i;i--){
            if((pos[i]-pos[i-1])<=dis || speed[i-1]>curr)cnt--;
            else curr=speed[i-1];
        }
        return cnt;
    }
};