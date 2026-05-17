class Solution {
public:
int n;
bool solve(long long i, vector<int>&arr,vector<bool>&vis){
    
    if(arr[i]==0)return true;
    if(vis[i])return false;
    vis[i]=true;
    bool left=false;
    if(i-arr[i]>=0)left=solve(i-arr[i],arr,vis);
    bool right=false;
    if(i+arr[i]<n)right=solve(i+arr[i],arr,vis);
    return left||right;
}
    bool canReach(vector<int>& arr, int start) {
        n=arr.size();
        vector<bool>vis(n,false);
        return solve(start,arr,vis);
    }
};