class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int cnt1=1,cnt2=1;
        int len1=hBars.size(),len2=vBars.size();
        int i=0;
        while(i<len1){
            int j=i;
            while(j<len1 && (j==i || hBars[j]==(1+hBars[j-1])))j++;
            cnt1=max(cnt1,j-i);
            i=j;
        }
        i=0;
        while(i<len2){
            int j=i;
            while(j<len2 && (j==i || vBars[j]==(1+vBars[j-1])))j++;
            cnt2=max(cnt2,j-i);
            i=j;
        }
        int mn=min(cnt1+1,cnt2+1);
        return mn*mn;
    }
};