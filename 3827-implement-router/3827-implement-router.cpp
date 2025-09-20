#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Router{
private:
    int n;
    deque<vector<int>> dq;
    unordered_set<string> st;
    unordered_map<int,ordered_set<pair<int,int>>> mpp;
    int nxt=0;
    string f(int s,int d,int t){
        return to_string(s)+"#"+to_string(d)+"#"+to_string(t);
    }
public:
    Router(int n):n(n){}
    bool addPacket(int src,int dst,int t){
        string key=f(src,dst,t);
        if(st.find(key)!=st.end())return false;
        if(dq.size()==(size_t)n){
            auto x=dq.front();dq.pop_front();
            int s=x[0],d=x[1],time=x[2],id=x[3];
            st.erase(f(s,d,time));
            auto it=mpp.find(d);
            if(it!=mpp.end()){
                it->second.erase({time,id});
                if(it->second.empty())mpp.erase(it);
            }
        }
        int id=nxt++;
        dq.push_back({src,dst,t,id});
        st.insert(key);
        mpp[dst].insert({t,id});
        return true;
    }
    vector<int> forwardPacket(){
        if(dq.empty())return {};
        auto x=dq.front();dq.pop_front();
        int s=x[0],d=x[1],time=x[2],id=x[3];
        st.erase(f(s,d,time));
        auto it=mpp.find(d);
        if(it!=mpp.end()){
            it->second.erase({time,id});
            if(it->second.empty())mpp.erase(it);
        }
        return {s,d,time};
    }
    int getCount(int dst,int s,int e){
        auto it=mpp.find(dst);
        if(it==mpp.end())return 0;
        pair<int,int> low={s,INT_MIN};
        pair<int,int> high={e,INT_MAX};
        return it->second.order_of_key(high)-it->second.order_of_key(low);
    }
};