class Solution {
#define ill long long int
#define ll long long
private:
    ill power(ill x, ill y) {
        return y ? ((y % 2 ? x : 1ll) * power((x * x), y / 2)) : 1ll;
    }
public:
    bool checkPowersOfThree(int n) {
        ill maxi=power(3,15);
        n=(ill)n;
        while(maxi){
            if(n>=maxi)n-=maxi;
            maxi/=3;
        }
        return !n;
    }
};