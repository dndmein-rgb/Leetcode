class Solution {
public:
    int characterReplacement(string s, int k) {
       vector<int>freq(256,0) ;
       int n=s.length();
       int i=0;
       int j=0;
       int maxLen=0,maxFreq=0;
       while(j<n){
        freq[s[j]]++;
        maxFreq=max(maxFreq,freq[s[j]]);
        while((j-i+1)-maxFreq>k){
            freq[s[i]]--;
            i++;
        }
        maxLen=max(j-i+1,maxLen);
        j++;
       }
       return maxLen;
    }
};