

class Solution {
public:
   public:
    int maxSubstrings(string word) {
        int n = word.length();
        int result = 0;
        
        // Stores the first occurrence index of each character ('a'-'z')
        // Initialize with -1 to indicate the character hasn't been seen yet
        vector<int> arr(26, -1);

        for (int i = 0; i < n; i++) {
            int idx = word[i] - 'a';

            // Check if we've seen this character and if the length is >= 4
            // Length is calculated as: current_index - start_index + 1
            if (arr[idx] != -1 && (i - arr[idx] + 1) >= 4) {
                result++;
                
                // GREEDY RESET: Clear all tracked starts to find the NEXT 
                // non-overlapping substring from the current position.
                fill(arr.begin(), arr.end(), -1);
            } 
            else {
                // If the character hasn't been recorded in this window, store its index
                if (arr[idx] == -1) {
                    arr[idx] = i;
                }
            }
        }

        return result;
    }
};