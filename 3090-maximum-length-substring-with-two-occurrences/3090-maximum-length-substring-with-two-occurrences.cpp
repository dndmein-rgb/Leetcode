class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int>freq(26,0);
        int n=s.length();
        int maxLen=0;
        int i=0;
        for(int j=0;j<n;j++){
            char c=s[j]-'a';
            freq[c]++;
            while(freq[c]>2){
                freq[s[i]-'a']--;
                i++;
            }
            maxLen=max(maxLen,j-i+1);
        }
        return maxLen;
    }
};