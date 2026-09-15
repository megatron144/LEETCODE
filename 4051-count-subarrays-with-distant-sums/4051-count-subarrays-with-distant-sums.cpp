class Solution {
public:
    long long cnt=0;
    void merge(int low, int mid, int high, vector<long long>& prefix,
               long long goal, long long k) {

        vector<long long> left(prefix.begin() + low, prefix.begin() + mid + 1);
        vector<long long> right(prefix.begin() + mid + 1, prefix.begin() + high + 1);
        int a=0,b=0;
        for(auto x : right){
            long long L=x-goal-k,R=x-goal+k;
            while(a<left.size() && left[a]<=L)a++;
            while(b<left.size() && left[b]<R)b++;
            cnt+=b-a;
        }
        int i = 0, j = 0;
        vector<long long> temp;
        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                temp.push_back(left[i++]);
            } else {
                temp.push_back(right[j++]);
            }
        }

        while (i < left.size())
            temp.push_back(left[i++]);

        while (j < right.size())
            temp.push_back(right[j++]);

        for (int i = 0; i < temp.size(); i++)
            prefix[low + i] = temp[i];
    }

    void mergeSort(int low, int high, vector<long long>& prefix,
                   long long goal, long long k) {

        if (low >= high)
            return;

        int mid = low + (high - low) / 2;

        mergeSort(low, mid, prefix, goal, k);
        mergeSort(mid + 1, high, prefix, goal, k);

        merge(low, mid, high, prefix, goal, k);
    }

    long long distantSubarrays(vector<int>& nums, int goal, int k) {
        int n = nums.size();
        if (k == 0)return 1LL * n * (n + 1) / 2;
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)prefix[i + 1] = prefix[i] + nums[i];
        cnt = 0;
        mergeSort(0, n, prefix, goal, k);
        long long total = 1LL * n * (n + 1) / 2;
        return total - cnt;
    }
};