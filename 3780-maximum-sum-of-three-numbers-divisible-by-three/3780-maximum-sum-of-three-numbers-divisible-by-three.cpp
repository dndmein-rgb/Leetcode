class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int>zero,one,two;
        int n=nums.size();
        for(int num:nums){
            if(num%3==0)zero.push_back(num);
            else if(num%3==1)one.push_back(num);
            else two.push_back(num);
        }
        sort(zero.begin(),zero.end(),greater<int>());
        sort(one.begin(),one.end(),greater<int>());
        sort(two.begin(),two.end(),greater<int>());

        int maxSum=0;
        if(zero.size()>=3){
            int currSum=0;
            for(int i=0;i<3;i++){
                currSum+=zero[i];
            }
            maxSum=max(maxSum,currSum);
        }
        if(one.size()>=3){
            int currSum=0;
            for(int i=0;i<3;i++){
                currSum+=one[i];
            }
            maxSum=max(maxSum,currSum);
        }
        if(two.size()>=3){
            int currSum=0;
            for(int i=0;i<3;i++){
                currSum+=two[i];
            }
            maxSum=max(maxSum,currSum);
        }
        if(!zero.empty() && !one.empty() && !two.empty()){
            int currSum=zero[0]+one[0]+two[0];
            maxSum=max(maxSum,currSum);
        }
        return maxSum;
    }
};