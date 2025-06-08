class Solution {
private:
    static bool cmp(int& x,int& y){
        return to_string(x)<to_string(y);
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> v;
        for(int i=0;i<n;i++){
            v.push_back(i+1);
        }
        sort(v.begin(),v.end(),cmp);
        return v;
    }
};