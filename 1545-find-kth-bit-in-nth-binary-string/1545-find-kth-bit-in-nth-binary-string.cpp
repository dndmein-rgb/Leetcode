class Solution {
public:
string inverse(string s){
    for(char &c:s){
        c=(c=='0')?'1':'0';
    }
    return s;
}
string reversed(string s){
    reverse(s.begin(),s.end());
    return s;
}
    char findKthBit(int n, int k) {
        string s="0";
        for(int i=2;i<=n;i++){
            string inverted=inverse(s);
            s=s+'1'+reversed(inverted);
        }
        return s[k-1];
    }
};