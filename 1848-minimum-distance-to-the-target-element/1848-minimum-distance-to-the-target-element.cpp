class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n=nums.size();
        if(nums[start]==target)return 0;
    int distance=1;

    while(true){
        int left=-1;
        if((start-distance)>=0)left=start-distance;
        int right=-1;
        if((start+distance)<n)right= start+distance;
       if((left!=-1 && nums[left]==target) || (right!=-1 && nums[right]==target))return distance;
       distance++;
    }
    return -1;
    }
};