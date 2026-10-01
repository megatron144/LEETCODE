class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        for (int tar = n; tar > 1; --tar) {
            int i=0;
            while(arr[i]!=tar)i++;
            if(i==tar-1)continue;
            if(i>0){
                reverse(arr.begin(),arr.begin()+i+1);
                ans.push_back(i+1);
            }
            reverse(arr.begin(), arr.begin() + tar);
            ans.push_back(tar);
        }
        return ans;
    }
};