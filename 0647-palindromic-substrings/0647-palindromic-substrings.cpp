class Solution {
public:
int n;
bool isPalindrome(int i,int j,string &s){
    if(i==j)return true;
    while(i<=j && j>=i && s[i]==s[j]){
        i++;
        j--;
    }
    return i>=j;
}
    int countSubstrings(string s) {
         n=s.length();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s))count++;
            }
        }
        return count;
    }
};