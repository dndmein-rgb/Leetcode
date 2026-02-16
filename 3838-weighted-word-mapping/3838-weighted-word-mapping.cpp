class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result;
        for(string& word:words){
            long long total=0;
            for(char c:word){
                total+=weights[c-'a'];
            }
            int mod=total%26;
            char mapping='z'-mod;
            result.push_back(mapping);
        }
        return result;
    }
};