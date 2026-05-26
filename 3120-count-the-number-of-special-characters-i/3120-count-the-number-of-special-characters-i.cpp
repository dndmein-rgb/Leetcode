class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> freq(256, 0);

        for(char c : word) {
            freq[c]++;
        }

        int count = 0;

        for(char c = 'A'; c <= 'Z'; c++) {
            if(freq[c] && freq[c + 32]) {
                count++;
            }
        }

        return count;
    }
};