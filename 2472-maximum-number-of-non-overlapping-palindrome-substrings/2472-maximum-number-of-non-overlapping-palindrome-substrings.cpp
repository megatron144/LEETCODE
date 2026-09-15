class Solution {
public:
    int maxPalindromes(string s, int K) {
        int n=s.size();
        if(K==1)return n;
        int cnt=0;
        for(int i=0;i<=n-K;){
            int inc=1;
            for(int k=K;k<=K+1;k++){
                if(i+k<=n && equal(s.begin()+i,
                                    s.begin()+i+(k>>1),
                                    s.rbegin()+(n-(i+k)))){
                    inc=k;
                    cnt++;
                    break;
                }
            }
            i+=inc;
        }
        return cnt;
    }
};