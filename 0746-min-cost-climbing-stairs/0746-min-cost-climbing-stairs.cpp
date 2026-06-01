class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
       if(n == 2)
            return min(cost[0], cost[1]);
        
        int t0 = cost[0];
        int t1 = cost[1];
        
        for(int i = 2; i<n; i++) {
            int temp = cost[i] + min(t0, t1);
            
            t0 = t1;
            t1 = temp;
        }
        
        return min(t0, t1);
    }
};