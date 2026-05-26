class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>freq(256,0);
        int count=0;
        for(char c:word){
            freq[c]++;
        }
        for(int i=65;i<=90;i++){
            if(freq[i]>0 && freq[i+32]>0)count++;
        }
        return count;
    }
};