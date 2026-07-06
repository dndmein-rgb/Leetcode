class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int>covered(n,0);
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        });
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                    int iFirst=intervals[i][0];
                    int iSecond=intervals[i][1];
                    int jFirst=intervals[j][0];
                    int jSecond=intervals[j][1];

                    if(iFirst<=jFirst && iSecond>=jSecond){
                        covered[j]=1;
                    }
            }
        }
        int ans=0;
        for(int c:covered){
            if(c==0)ans++;

        }
        return ans;
    }
};