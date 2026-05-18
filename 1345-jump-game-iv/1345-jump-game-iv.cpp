class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>>mp;
        vector<bool>visited(n,false);
        queue<int>q;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        q.push(0);
        visited[0]=true;
        int steps=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int curr=q.front();
                q.pop();
                if(curr==n-1)return steps;

                if(curr-1 >=0 && !visited[curr-1]){
                    visited[curr-1]=true;
                    q.push(curr-1);
                }
                if(curr+1 <n && !visited[curr+1]){
                    visited[curr+1]=true;
                    q.push(curr+1);
                }
                for(int idx:mp[arr[curr]]){
                    if(!visited[idx]){
                        visited[idx]=true;
                        q.push(idx);
                    }
                }
                 mp[arr[curr]].clear();
            }
            steps++;
        }
        return -1;
    }
};