class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k%2==0 ||k%5==0)return -1;
        long long num=1;
        int count=1;
        while(count<=k){
            num=(num*10+1)%k;
            count++;
            if(num%k==0)return count;
        }return -1;
    }
};