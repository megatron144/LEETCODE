class Solution {
    vector<vector<bool>> dp;
private:
    bool check(int x, int y, int currx, int curry, int target) {
        if (currx + curry == target || currx == target || curry == target) 
            return true;

        if (dp[currx][curry]) 
            return false;
        
        dp[currx][curry] = true;

        // 1. Fill X
        if (check(x, y, x, curry, target)) return true;
        // 2. Fill Y
        if (check(x, y, currx, y, target)) return true;
        // 3. Empty X
        if (check(x, y, 0, curry, target)) return true;
        // 4. Empty Y
        if (check(x, y, currx, 0, target)) return true;

        // 5. Pour X -> Y
        int pourXtoY = std::min(currx, y - curry);
        if (check(x, y, currx - pourXtoY, curry + pourXtoY, target)) return true;

        // 6. Pour Y -> X
        int pourYtoX = std::min(curry, x - currx);
        if (check(x, y, currx + pourYtoX, curry - pourYtoX, target)) return true;
        return false;
    }
public:
    bool canMeasureWater(int x, int y, int target) {
        if((x+y)==target)return true;
        if((x+y)<target)return false;
        dp.assign(x+1,vector<bool> (y+1,false));
        return check(x,y,0,0,target);
        //return !(target%gcd(x,y));
    }
};