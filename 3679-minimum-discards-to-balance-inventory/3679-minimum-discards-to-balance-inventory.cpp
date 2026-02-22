class Solution {
public:
    int minArrivalsToDiscard(vector<int>& a, int w, int m) {
        unordered_map<int,int> mp;
        int n = a.size();
        int discards = 0;

        vector<bool> kept(n, false);

        for(int j = 0; j < n; j++) {

            // Remove element that falls out of window
            if(j - w >= 0 && kept[j - w]) {
                mp[a[j - w]]--;
            }

            // Try keeping current
            if(mp[a[j]] < m) {
                mp[a[j]]++;
                kept[j] = true;
            } else {
                discards++;
                kept[j] = false;  // explicitly discard
            }
        }

        return discards;
    }
};