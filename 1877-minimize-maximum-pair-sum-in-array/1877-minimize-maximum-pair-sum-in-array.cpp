class Solution {
public:
    int minPairSum(vector<int>& nums) {
       int n=nums.size() ;
       int maxSum=0;
       priority_queue<int,vector<int>,greater<int>>minH;
       priority_queue<int>maxH;
       for(int &num:nums){
        minH.push(num);
        maxH.push(num);
       }
       while(!minH.empty()&&!maxH.empty()){
        maxSum=max(maxSum,minH.top()+maxH.top());
        minH.pop();
        maxH.pop();
       }
       return maxSum;
    }
};