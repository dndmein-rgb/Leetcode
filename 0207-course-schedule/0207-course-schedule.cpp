class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        queue<int>q;
        for(auto& p:prerequisites){
            int u=p[0];
            int v=p[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            count++;
            for(int nei:adj[front]){
                indegree[nei]--;
                if(indegree[nei]==0)q.push(nei);
            }
        }
        return numCourses==count;
    }
};