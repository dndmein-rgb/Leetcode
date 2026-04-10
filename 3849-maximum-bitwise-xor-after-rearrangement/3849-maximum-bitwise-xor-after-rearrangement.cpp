class Solution {
public:
    string maximumXor(string s, string t) {
        int n=s.length();
        int zeros=0,ones=0;
        for(int i=0;i<n;i++){
            if(t[i]=='0')zeros++;
            else ones++;
        }
      string ans;
      for(char c:s){
        if(c=='1' && zeros){
            ans.push_back('1');
            zeros--;
        }else if(c=='0' && ones){
            ans.push_back('1');
            ones--;
        }else ans.push_back('0');
      }
      return ans;
    }
};