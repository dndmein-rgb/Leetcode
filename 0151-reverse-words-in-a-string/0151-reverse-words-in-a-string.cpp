class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        int i=0;
        vector<string>result;
        while(i<n){
            while(i<n && s[i]==' ')i++;
            int j=i;
            while(j<n&&s[j]!=' ')j++;
           ;
            if (i < n) {
    result.push_back(s.substr(i, j - i));
}
            i=j;
        }
        reverse(result.begin(),result.end());
        string ans="";
        for(int i=0;i<result.size();i++){
            ans=ans+result[i]+(i==result.size()-1 ? "":" ");
        }
return ans;
    }
};