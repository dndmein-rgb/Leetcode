#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        const int MOD = 1e9 + 7;
        
        // countT1[v]: Ways a sequence ended such that it's now waiting for target1.
        // countT2[v]: Ways a sequence ended such that it's now waiting for target2.
        unordered_map<int, int> countT1;
        unordered_map<int, int> countT2;

        // Base case: Before index 0, we have 1 way (XOR 0) waiting for target1.
        countT1[0] = 1;

        int currentXor = 0;
        int totalWaysAtEnd = 0;

        for (int x : nums) {
            currentXor ^= x;
            
            // Calculate transitions for this index separately to avoid double-counting.
            int waysToFinishT1 = 0;
            int waysToFinishT2 = 0;

            // 1. Can we finish a target1 block here?
            int prevForT1 = currentXor ^ target1;
            if (countT1.count(prevForT1)) {
                waysToFinishT1 = countT1[prevForT1];
            }

            // 2. Can we finish a target2 block here?
            int prevForT2 = currentXor ^ target2;
            if (countT2.count(prevForT2)) {
                waysToFinishT2 = countT2[prevForT2];
            }

            // Now update the maps. The transitions move T1 -> T2 and T2 -> T1.
            if (waysToFinishT1 > 0) {
                countT2[currentXor] = (countT2[currentXor] + waysToFinishT1) % MOD;
            }
            if (waysToFinishT2 > 0) {
                countT1[currentXor] = (countT1[currentXor] + waysToFinishT2) % MOD;
            }

            // A valid partition is one that finishes a block exactly at the current index.
            totalWaysAtEnd = (waysToFinishT1 + waysToFinishT2) % MOD;
        }

        return totalWaysAtEnd;
    }
    
};