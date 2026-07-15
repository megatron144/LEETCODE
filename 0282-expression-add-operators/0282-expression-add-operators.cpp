class Solution{
    public:
    void help(int i, string sumPath, long sum, long prev, string num, int target, vector<string> &result)
    {
        if(i==num.size()){
           if(sum==target)result.push_back(sumPath);
            return;
        }
        for (int j = i; j < num.size(); j++){
            if (j > i && num[i] == '0')continue;
            long number = stol(num.substr(i, j - i + 1));
            string tempPath = num.substr(i, j - i + 1);
            if (i == 0)help(j + 1, tempPath, number, number, num, target, result);
            else{
                help(j+1,sumPath+'+'+tempPath,sum+number,number,num,target,result);
                help(j+1,sumPath+'-'+tempPath,sum-number,-number,num,target,result);
                help(j+1,sumPath+'*'+tempPath,sum-prev+(prev*number),prev*number,num,target,result);
            }
        }
    }
    vector<string> addOperators(string num, int target)
    {
        vector<string> result;
        help(0, "", 0, 0, num, target, result);
        return result;
    }
};