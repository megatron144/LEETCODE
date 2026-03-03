class Solution {
public:
    char findKthBit(int n, int k) {
        long long len=(long long)pow(2,n)-1;
        int tmp=k;
        int swaps=0;
        while(len!=1){
            if(tmp==len/2+1)return (swaps&1)?'0':'1';
            if(tmp>len/2+1){
                swaps++;
                tmp=tmp-len/2-1;
                len/=2;
                tmp=len+1-tmp;
            }
            else len/=2;
        }
        return (swaps&1)?'1':'0';
    }
};