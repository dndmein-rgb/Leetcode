class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int minPrice=1e9;
      int maxProfit=0;
      for(int p:prices)  {
        minPrice=min(minPrice,p);
        maxProfit=max(maxProfit,p-minPrice);
      }
      return maxProfit;
    }
};