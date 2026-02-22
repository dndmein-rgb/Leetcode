class Solution {
public:
string binaryRep(int n){
    string ans;
    while(n){
        int digit=n&1;
        ans.push_back(digit+'0');
        n>>=1;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
    int binaryGap(int n) {
        string s=binaryRep(n);
        int len=s.length();
        
        int maxLen=0;
        for(int i=0;i<len;i++){
            if(s[i]=='1'){
                int j=i+1;
              if(i+1<len){
                while(j<len){
                   if(s[j]=='1'){
                        maxLen=max(maxLen,j-i);
                        break;
                    }
                    j++;
                }
              }
            }
        }
        return maxLen;
    }
};