class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        unordered_map<int,vector<int>>indices;
        for(int i=0;i<n;i++){
            indices[nums[i]].push_back(i);
        }
          vector<int> minDist(n, INT_MAX);
        for(auto &p:indices){

            auto&v=p.second;
            int m=v.size();
          if (m == 1) {
                minDist[v[0]] = -1;
                continue;
            }
            for(int i=0;i<m;i++){
                int prev=v[(i-1+m)%m];
                int curr=v[i];
                int next=v[(i+1+m)%m];
                 
                int distPrev = min(abs(curr - prev), n - abs(curr - prev));
                int distNext = min(abs(curr - next), n - abs(curr - next));
                minDist[curr]=min(distPrev,distNext);
            }
        }
         vector<int> result;
        for (int query : queries) {
            result.push_back(minDist[query]);
        }
        
        return result;
    }
};