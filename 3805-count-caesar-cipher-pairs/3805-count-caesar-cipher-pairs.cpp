class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string,long long >freq;
        long long ans=0;
        for(string& w:words){
            int diff=w[0]-'a';
            for(char& c:w){
                c-=diff;
                if(c<'a')c+=26;
                
            }
            ans+=freq[w];
            freq[w]++;
        }
        return ans;
    }
};