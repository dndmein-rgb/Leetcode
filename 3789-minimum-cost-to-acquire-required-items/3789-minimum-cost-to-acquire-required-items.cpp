class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long minCost=1e18;
        //case 1
        long long  totalCost=(long)cost1*need1+(long)cost2*need2;
        minCost=min(minCost,totalCost);
        //case 2
        totalCost=max(need1,need2)*(long)costBoth;
         minCost=min(minCost,totalCost);

         //case 3
         if(need1<need2){
            totalCost=costBoth*(long)need1+(need2-need1)*(long)cost2;
              minCost=min(minCost,totalCost);
         }
         else {
            totalCost=costBoth*(long)need2+(need1-need2)*(long)cost1;
            minCost=min(minCost,totalCost);
         }
         return minCost;
    }
};