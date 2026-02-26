class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(), pizzas.end());
        int n = pizzas.size();
        int m = n / 4;
        
        int odd = (m + 1) / 2;
        int even = m / 2;
        
        long long total = 0;
        int i = n - 1;
        
        while (odd--) {
            total += pizzas[i];
            i--;
        }
        
        while (even--) {
            i--;              // skip biggest
            total += pizzas[i]; // take second biggest
            i--;
        }
        
        return total;
    }
};