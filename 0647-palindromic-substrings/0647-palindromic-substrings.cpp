class Solution {
public:
int n;
    int expand(int i,int j,string&s){
        int count=0;
        while(i>=0 && j<n  && s[i]==s[j]){
            i--;
            j++;
            count++;
        }
        return count;
    }

    int countSubstrings(string s) {
         n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=expand(i,i,s);
            ans+=expand(i,i+1,s);
        }
        return ans;
    }
};