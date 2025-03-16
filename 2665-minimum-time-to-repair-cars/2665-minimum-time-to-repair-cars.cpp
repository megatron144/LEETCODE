class Solution {
#define T tuple<long long,int,int>
private:
    static bool cmp(const T&a,const T&b){
        return get<0>(a)>get<0>(b);
    };
public:
    long long repairCars(vector<int>& ranks, int cars) {
        priority_queue<T,vector<T>,bool(*)(const T&,const T&)>pq(cmp);
        for(int r:ranks){
            pq.push({(long long)r,0,r});
        }
        long long ans=0;
        for(int i=0;i<cars;i++){
            auto [time,count,r]=pq.top();
            pq.pop();
            ans=time;
            count++;
            long long newTime=(long long)r*(count+1LL)*(count+1LL);
            pq.push({newTime,count,r});
        }
        return ans;
    }
};
