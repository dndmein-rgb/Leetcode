class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.length();
        
        vector<int> px(n+1, 0), py(n+1, 0);
        
        // Build prefix sums
        for(int i = 0; i < n; i++) {
            px[i+1] = px[i];
            py[i+1] = py[i];
            
            if(s[i] == 'U') py[i+1]++;
            else if(s[i] == 'D') py[i+1]--;
            else if(s[i] == 'R') px[i+1]++;
            else px[i+1]--;
        }
        
        int total_x = px[n];
        int total_y = py[n];
        
        set<pair<int,int>> ans;
        
        for(int l = 0; l + k <= n; l++) {
            int r = l + k;
            
            int dx = px[r] - px[l];
            int dy = py[r] - py[l];
            
            int final_x = total_x - dx;
            int final_y = total_y - dy;
            
            ans.insert({final_x, final_y});
        }
        
        return ans.size();
    }
};