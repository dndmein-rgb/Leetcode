class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for (auto& q : prerequisites) {
            int u = q[0];
            int v = q[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if(indegree[i]==0)q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(int nei:adj[node]){
                indegree[nei]--;
                if(indegree[nei]==0)q.push(nei);
            }
        }
        return numCourses==count;
    }
};