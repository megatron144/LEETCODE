class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        // int mn=min(x,y),mx=x+y-mn;
        // if(mn==mx && mx==1){
        //     if(bound<2)return {};
        //     return {2};
        // }
        // vector<int> v;
        // if(mn==1){
        //     int curr=1;
        //     while(curr+1<bound)v.push_back(curr+1);curr*=mx;
        //     return v;
        // }
        unordered_set<int> s;
        for(int i=1;i<=bound;i*=x){
            for (int j=1;i+j<=bound;j*=y){
                s.insert(i+j);
                if(y==1)break;
            }
            if(x==1)break;

        }
        return vector<int>(s.begin(), s.end());
    }
};