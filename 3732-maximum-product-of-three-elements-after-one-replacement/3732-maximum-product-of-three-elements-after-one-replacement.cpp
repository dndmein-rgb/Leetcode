class Solution {
public:
    long long maxProduct(vector<int>& nums) {
       priority_queue<int>pq;
       for(int num:nums) {
        pq.push(abs(num));
       }
       long long product=1;
       int count=2;
       while(count){
        int front=pq.top();
    product*=front;
    pq.pop();
    count--;
       }
       return product*100000;
    }
};