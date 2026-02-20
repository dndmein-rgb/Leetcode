class ExamTracker {
public:
    vector<int> times;
    map<int, long long int> mp;
    ExamTracker() {}

    void record(int time, int score) {
        if (times.size() == 0) {
            mp[time] = score;
            times.push_back(time);
        } else {
            mp[time] = score;
            mp[time] += mp[times.back()];
            times.push_back(time);
        }
    }

    long long totalScore(int startTime, int endTime) {

        long long int s = 0;
        long long int e = 0;
        auto it = mp.lower_bound(startTime);

        if (it == mp.begin()) {
            s = 0;
        } else {
            it--;
            s = it->second;
        }

        auto it2 = mp.upper_bound(endTime);
       
        if(it2!=mp.begin()){
             it2--;
             e = it2->second;
        }
       


        long long ans = e - s;
        return ans;
    }
};


 