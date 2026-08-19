class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        for (auto& seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

            rows[row] |= (1 << (s - 1));
        }


        int ans = (n - rows.size()) * 2;

        int left   = 0b0000011110; // seats 2,3,4,5
        int middle = 0b0001111000; // seats 4,5,6,7
        int right  = 0b0111100000; // seats 6,7,8,9

        for (auto& [row, reserved] : rows) {
            
            if ((reserved & left) == 0 &&
                (reserved & right) == 0) {
                ans += 2;
            }

            else if ((reserved & left) == 0 ||
                     (reserved & middle) == 0 ||
                     (reserved & right) == 0) {
                ans += 1;
            }
        }

        return ans;
    }
};