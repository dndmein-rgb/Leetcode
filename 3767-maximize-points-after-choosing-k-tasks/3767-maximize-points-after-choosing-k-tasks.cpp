class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();
        vector<int> dist(n);
        for(int i = 0; i < n; i++) {
            dist[i] = technique1[i] - technique2[i];
        }

        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < n; i++) {
            pq.push({dist[i], i});
        }

        long long totalSum = 0;
        while (!pq.empty()) {
            auto [val, i] = pq.top();
            pq.pop();

           
            if (k > 0) {
                totalSum += technique1[i];
                k--;
            } 
            
            else {
                totalSum += max(technique1[i], technique2[i]);
            }
        }
        return totalSum;
    }
};