class Solution {
public:
    long long countPairs(vector<string>& words) {

        unordered_map<string, int> mp;

        for (string s : words) {
            mp[s]++;
        }
        long long int count = 0;
        unordered_map<string, int> m; //transformations
        for (string s : words) {

            if (m.find(s) != m.end()) {
                continue;
            }

            long long int ans =0;
           
            for (int j = 0; j < 26; j++) {
                string t = s;
                for (int i = 0; i < t.size(); i++) {
                    int val = t[i] - 'a';
                    val = (val + j) % 26;
                    t[i] = 'a' + val;
                }
                m[t]++;
               ans+=mp[t];
                
            }
            count += (ans * 1LL * (ans - 1)) / 2;
        }

        return count;
    }
};