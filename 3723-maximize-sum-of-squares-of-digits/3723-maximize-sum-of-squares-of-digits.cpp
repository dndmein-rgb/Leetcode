class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans;
        while(num){
            if(sum>=9){
                ans.push_back(9 +'0');
                sum-=9;
                num--;
            }
            else if(sum<9){
                ans.push_back(sum+'0');
                sum-=sum;
                num--;
            }
        }
        return sum==0? ans:"";
    }
};