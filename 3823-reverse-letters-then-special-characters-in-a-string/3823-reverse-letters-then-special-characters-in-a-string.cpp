class Solution {
public:
    string reverseByType(string s) {
        string original = "", special = "";
        for(char c:s){
             if(c>='a' && c<='z')original.push_back(c);
             else special.push_back(c);
        }
       
    reverse(original.begin(), original.end());   
    reverse(special.begin(), special.end());

        int i=0,j=0;
        for(int k=0;k<s.length();k++){
            if(s[k]>='a'&&s[k]<='z'){
                s[k]=original[i++];
            }
            else s[k]=special[j++];
        }
       
        return s;
    }
};