class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num*9<sum)return "";
        string str="";
        int cnt=sum/9;
        num-=cnt;
        while(cnt--)str+='9';
        cout<<str<<endl;
        int rem=sum%9;
        if(rem)str+=(char)(rem+'0'),num--;
        cout<<str<<endl;
        while(num>0)str+='0',num--;
        return str;
    }
};