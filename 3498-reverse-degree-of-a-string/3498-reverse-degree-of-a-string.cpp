class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for ( int i=0;i<s.length();i++){
            char c=s[i];
            int num='z'-c+1;
            ans+=num*(i+1);
            cout<<ans<<endl;
            cout<<i<<endl;
        }
        return ans;
    }
};