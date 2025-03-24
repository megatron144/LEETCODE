class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int ans=0;
        ans+=meetings[0][0]-1;
        int n=meetings.size(),i=1,maxi=meetings[0][1];
        while(i<n){
            if(maxi>=meetings[i][0]){
                maxi=max(maxi,meetings[i][1]);
                i++;
            }
            else{
                ans+=meetings[i][0]-maxi-1;
                maxi=meetings[i][1];
                i++;
            }
        }
        if(days>maxi)
            ans+=days-maxi;
        return ans;
    }
};