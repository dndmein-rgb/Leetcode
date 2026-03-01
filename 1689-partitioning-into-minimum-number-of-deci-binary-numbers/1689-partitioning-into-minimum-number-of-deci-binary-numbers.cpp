class Solution {
public:
    int minPartitions(string n) {
        int maxNum=0;
        for(char c:n){
            if(maxNum<c-'0')maxNum=c-'0';
        }
        return maxNum;
    }
};