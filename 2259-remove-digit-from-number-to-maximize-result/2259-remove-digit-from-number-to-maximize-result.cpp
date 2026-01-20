class Solution {
public:
    string removeDigit(string number, char digit) {
        int n=number.length();
        int lastIdx=-1;
    for(int i=0;i<n;i++){
        if(number[i]==digit){
            lastIdx=i;
            if(i+1<n && number[i+1]>digit)return number.substr(0,i)+number.substr(i+1);
        }
    }
    return number.substr(0,lastIdx)+number.substr(lastIdx+1);
    }
};