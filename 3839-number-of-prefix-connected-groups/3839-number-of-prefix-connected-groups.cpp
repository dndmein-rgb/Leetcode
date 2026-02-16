class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        sort(words.begin(),words.end());
        unordered_map<string,int>mp;
        for(auto& word:words){
            if(word.length()<k)continue;
            string toCheck=word.substr(0,k);
            mp[toCheck]++;
        }
        int count=0;
        for(auto& s:mp){
            if(s.second>1)count++;
        }
        return count;
    }
};