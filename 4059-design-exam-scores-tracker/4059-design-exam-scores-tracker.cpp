class ExamTracker {
public:
    long long score=0;
    vector<long long> v,t;
    ExamTracker() {
        v.push_back(score);
        t.push_back(0);
    }
    void record(int time, int val) {
        score+=(long long)val;
        v.push_back(score);
        t.push_back(time);
    }
    long long totalScore(int st, int en) {
        int l=lower_bound(t.begin(),t.end(),st)-t.begin(),r=upper_bound(t.begin(),t.end(),en)-t.begin();
        return v[r-1]-v[l-1];
    }
};
/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */