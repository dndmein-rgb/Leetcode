class Solution {
public:
int start=0,maxLen=1;
void expand(int i,int j,string&s){
     int n=s.length();
     while(i>=0 && j<n && s[i]==s[j]){
        int len=j-i+1;
        if(len>maxLen){
            maxLen=len;
            start=i;
        }
        i--;
        j++;
        
     }
     
}
    string longestPalindrome(string s) {
        int n=s.length();
        for(int i=0;i<n;i++){
           expand(i,i+1,s);
          expand(i,i,s);
        }
        return s.substr(start,maxLen);
    }
};