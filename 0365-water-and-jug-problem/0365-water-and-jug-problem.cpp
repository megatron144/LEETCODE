class Solution {
// private:
//     bool check(int& x,int& y,int currx,int curry,int& target){
//         if((currx+curry)==target)return true;
//         if(!currx && curry){
//             bool flg=check(x,y,x,curry,target);
//             //y->x
//             if(curry>=x)flg|=check(x,y,x,curry-x,target);
//             else flg|=check(x,y,curry,0,target);
//             return flg;
//         }
//         if(!curry && currx){
//             bool flg=check(x,y,currx,y,target);
//             //x->y
//             if(currx>=y)flg|=check(x,y,currx-y,y,target);
//             else flg|=check(x,y,0,currx,target);
//             return flg;
//         }
//         bool flg=check(x,y,x,curry,target)|check(x,y,currx,y,target);
//         //x->y
//         {
//             if((currx+curry)<=y)flg|=check(x,y,0,currx+curry,target);
//             else flg|=check(x,y,currx-(y-curry),y,target);
//         }
//         //y->x
//         {
//             if((currx+curry)<=x)flg|=check(x,y,currx+curry,0,target);
//             else flg|=check(x,y,x,curry-(x-currx),target);
//         }
//         return flg;
//     }
public:
    bool canMeasureWater(int x, int y, int target) {
        if((x+y)==target)return true;
        if((x+y)<target)return false;
        return !(target%gcd(x,y));
    }
};