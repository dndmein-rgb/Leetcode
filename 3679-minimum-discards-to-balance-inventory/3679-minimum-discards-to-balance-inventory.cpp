class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        map<int, int> mp;
        int n = arrivals.size();
        int count = 0;
        vector<int> dis(n, 0);

        for (int i = 0; i < w; i++) {
            mp[arrivals[i]]++;
            if (mp[arrivals[i]] > m) {
                dis[i] = 1;
                mp[arrivals[i]]--;
                count++;
            }
        }

        for (int i = w; i < n; i++) {
            mp[arrivals[i]]++;
            if (mp[arrivals[i - w]] > 0 && dis[i - w] == 0) {
                mp[arrivals[i - w]]--;
            }

            if (mp[arrivals[i]] > m) {
                mp[arrivals[i]]--;
                dis[i] = 1;
                count++;
            }
        }

        return count;
    }
};