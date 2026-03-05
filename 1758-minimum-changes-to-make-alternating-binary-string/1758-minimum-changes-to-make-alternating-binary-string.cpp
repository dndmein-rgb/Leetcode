class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        string t=s;
        int count1=0,count2=0;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                count1++;
                if(s[i]=='1')s[i+1]='0';
                else s[i+1]='1';
            }
        }
        if(t[0]=='0')t[0]='1';
        else t[0]='0';
        for(int i=0;i<n-1;i++){
            if(t[i]==t[i+1]){
                count2++;
                if(t[i]=='1')t[i+1]='0';
                else t[i+1]='1';
            }
        }
    return min(count1,count2+1);
    }
};