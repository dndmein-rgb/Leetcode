class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        for(int i = 0; i < n; i++) {

            vector<int> test = sorted;

            rotate(test.begin(), test.begin() + i, test.end());

            if(test == nums) {
                return true;
            }
        }

        return false;
    }
};