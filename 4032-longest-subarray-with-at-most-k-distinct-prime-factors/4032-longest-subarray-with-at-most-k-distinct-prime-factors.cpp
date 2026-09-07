class Solution {
private:
    vector<int> spf;
    vector<vector<int>> div;
    void genSpf(int x) {
        spf.resize(x+1,0);
        for(int i=0;i<=x;i++)spf[i]=i;
        for(int i=2;i*i<=x;i++){
            if(spf[i]==i){
                for(int j=i*i;j<=x;j+=i){
                    if(spf[j]==j)spf[j]=i;
                }
            }
        }
    }
    void genDiv(int x){
        if(!div[x].empty())return;
        int tmp=x;
        while(tmp>1){
            int curr=spf[tmp];
            div[x].push_back(curr);
            while(tmp%curr==0)tmp/=curr;
        }
    }
public:
    int longestSubarray(vector<int>& nums, int k) {
        int mx=*max_element(nums.begin(),nums.end()),n=nums.size();
        genSpf(mx);
        div.resize(mx+1);
        for(auto x: nums)genDiv(x);
        vector<int> cnt(mx+1,0);
        mx=0;
        int i=0,pcnt=0;
        for(int j=0;j<n;j++){
            for(auto x: div[nums[j]]){
                if(cnt[x]==0)pcnt++;
                cnt[x]++;
            }
            while(pcnt>k){
                for(auto x: div[nums[i]]){
                    cnt[x]--;
                    if(cnt[x]==0)pcnt--;
                }
                i++;
            }
            mx=max(mx,j-i+1);
        }
        return mx;
    }
};