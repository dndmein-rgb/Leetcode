class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string, int> mp;
       
        int n = word.size();

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string s = word.substr(i, j - i + 1);
               mp[s]++;
            }
        }
        for(auto& s:patterns){
            if(mp.count(s))count++;
        }
        return count;
    }
};