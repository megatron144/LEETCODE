class Solution {
private:
    vector<string> v;
    int N;
    void f(string s,int i){
        if(i==N){
            v.push_back(s);
            return;
        }
        f(s+"1",i+1);
        f(s+"0",i+1);
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // N=nums.size();
        // f("",0);
        // for(auto x: v){
        //     if(find(nums.begin(),nums.end(),x)==nums.end())return x;
        // }
        // return "";
        string ans;
        for(int i=0;i<nums.size();i++)ans+=nums[i][i]=='0'?'1':'0';
        return ans;
    }
};