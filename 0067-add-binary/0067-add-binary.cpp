class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.length();
        int m=b.length();
        int i=n-1,j=m-1;
        int carry=0;
        string ans="";
        while(carry || i>=0 || j>=0 ){
            int sum=carry;
            if(i>=0)sum+=a[i--]-'0';
            if(j>=0)sum+=b[j--]-'0';
            ans+=sum%2+'0';
            carry=sum/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};