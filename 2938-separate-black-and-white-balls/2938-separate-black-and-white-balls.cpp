class Solution {
public:
    long long minimumSteps(string s) {
        int ones=0;
        long long ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='0')ans+=ones;
            else ones++;
        }
        return ans;
    }
};