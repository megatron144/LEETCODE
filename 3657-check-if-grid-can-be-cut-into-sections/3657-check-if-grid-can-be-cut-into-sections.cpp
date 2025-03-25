const int N=100000;
using int2=pair<int, int>;
int2 X[N], Y[N];
class Solution {
public:
    bool cut3(int2* X, int M){
        sort(X, X+M);
        int b=X[0].second, cnt=0;
        for(int i=1; i<M; i++){
            const int c=X[i].first, d=X[i].second;
            if (c<b) //merge
                b=max(b, d);
            else{// cut once
                cnt++;
                b=d;
            }
            if (cnt>=2) return 1;
        }
        return 0;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        const int m=rectangles.size();
        int i=0;
        for(auto& r: rectangles){
            const int xs=r[0], ys=r[1], xe=r[2], ye=r[3];
            X[i].first=xs; Y[i].first=ys;
            X[i].second=xe; Y[i].second=ye; 
            i++;
        }
        return cut3(X, m) || cut3(Y, m);
    }
};