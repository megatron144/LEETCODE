class Solution {
private:
    inline static int block=1;
    static bool cmp(vector<int>& a,vector<int>& b){
        if(a[0]/block!=b[0]/block)return a[0]/block<b[0]/block;
        return a[1]<b[1];
    }
public:
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n=nums.size(),q=queries.size();
        block=max(1,(int)sqrt(n));
        vector<vector<int>> qn(q,vector<int>(3));
        for(int i=0;i<q;i++){
            qn[i][0]=queries[i][0];
            qn[i][1]=queries[i][1];
            qn[i][2]=i;
        }
        sort(qn.begin(),qn.end(),cmp);
        vector<bool> res(q,false);
        int l=0,r=-1,uniq=0,odd=0;
        vector<int> freq(*max_element(nums.begin(),nums.end())+1,0);
        for(auto& x: qn){
            int low=x[0],high=x[1],idx=x[2];
            //add towards left
            if(l>low){
                while(l>low){
                    l--;
                    freq[nums[l]]++;
                    if(freq[nums[l]]==1)uniq++;
                    if(freq[nums[l]]&1)odd++;
                    else odd--;
                }
            }
            if(l<low){
                while(l<low){
                    freq[nums[l]]--;
                    if(freq[nums[l]]==0)uniq--;
                    if(freq[nums[l]]&1)odd++;
                    else odd--;
                    l++;
                }
            }
            if(r<high){
                while(r<high){
                    r++;
                    freq[nums[r]]++;
                    if(freq[nums[r]]==1)uniq++;
                    if(freq[nums[r]]&1)odd++;
                    else odd--;
                }
            }
            if(r>high){
                while(r>high){
                    freq[nums[r]]--;
                    if(freq[nums[r]]==0)uniq--;
                    if(freq[nums[r]]&1)odd++;
                    else odd--;
                    r--;
                }
            }
            if(uniq==k && !odd)res[idx]=true;
        }
        return res;
    }
};