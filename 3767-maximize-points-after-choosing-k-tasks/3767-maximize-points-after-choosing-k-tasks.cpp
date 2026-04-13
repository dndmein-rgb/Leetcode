class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();
        priority_queue<pair<int, int>> pq;
        
        for (int i = 0; i < n; i++) {
            // Priority queue helps us find which tasks are "best" for technique1
            pq.push({technique1[i] - technique2[i], i});
        }

        long long totalSum = 0;
        int countTech1 = 0;

        while (!pq.empty()) {
            auto [diff, i] = pq.top();
            pq.pop();

            // 1. We MUST pick technique1 for the first k items we pull from the heap
            // because these are the items where technique1 performs best relative to tech2.
            if (countTech1 < k) {
                totalSum += technique1[i];
                countTech1++;
            } 
            // 2. For the rest, we have met our requirement, so just pick the maximum.
            else {
                totalSum += max(technique1[i], technique2[i]);
            }
        }
        return totalSum;
    }
};