class Solution {
public:
    long long minimumCost(long long cost1, long long cost2, long long costBoth, long long need1, long long need2) {
        long long totalCost=1e9;
        totalCost=(cost1*need1)+(cost2*need2);

        totalCost=min(totalCost,(max(need1,need2)*costBoth));

        if(need1<need2){
            totalCost=min(totalCost,(need1*costBoth+(need2-need1)*cost2));
        }else{
             totalCost=min(totalCost,(need2*costBoth+(need1-need2)*cost1));
        }
        return totalCost;
    }
};