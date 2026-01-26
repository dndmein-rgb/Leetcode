class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
       vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        int minDiff=1e9;
        for(int i=0;i<n-1;i++){
            if((arr[i+1]-arr[i])==minDiff)ans.push_back({arr[i],arr[i+1]});
            if((arr[i+1]-arr[i])<minDiff){
                while(!ans.empty()){
                    ans.pop_back();
                }
                minDiff=arr[i+1]-arr[i];
                ans.push_back({arr[i],arr[i+1]});
            }
            
        }
        return ans;
    }
};