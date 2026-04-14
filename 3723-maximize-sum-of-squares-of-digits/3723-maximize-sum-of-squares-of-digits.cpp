class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
      
       string s;
       while(sum>=9&& num){
        s.push_back('9');
        sum-=9;
        num--;
       }
       while(num){
        s.push_back(sum+'0');
        num--;
        sum=0;
       }
       if(sum)return "";
       
       return s;
    }

};