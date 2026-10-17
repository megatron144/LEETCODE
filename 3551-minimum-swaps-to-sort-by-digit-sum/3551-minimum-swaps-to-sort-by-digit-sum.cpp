class Solution {
private:
    static bool cmp(int& a,int& b){
        int s1=0,s2=0;
        int t1=a,t2=b;
        while(t1!=0 || t2!=0){
            s1+=(t1%10),s2+=(t2%10);
            t1/=10,t2/=10;
        }
        return s1==s2?a<b:s1<s2;
    }
public:
    int minSwaps(vector<int>&nums){
        int n=nums.size();
        vector<int> a(nums),b(nums);
        sort(b.begin(),b.end(),cmp);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)mp[b[i]]=i;
        vector<bool> vis(n);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]||mp[a[i]]==i)continue;
            int c=0,j=i;
            while(!vis[j]){
              vis[j]=1;
              j=mp[a[j]];
              c++;
            }
            ans+=c-1;
        }
        return ans;
    }
};