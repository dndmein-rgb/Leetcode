class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int n = cost.size();
        int total = 0;
        int count=0;
        for(int c:cost){
            if(count!=2){
                total+=c;
                count++;
            }
            else count=0;
        }
        return total;
    }
};