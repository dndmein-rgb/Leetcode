class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st(nums.begin(),nums.end());
        int maxL=0;
        for(int num:st){
            if(!st.count(num-1)){
                int  newStart=num;
                int count=1;
                while(st.count(newStart+1)){
                    newStart++;
                    count++;
                }
                maxL=max(maxL,count);
            }
        }
            return maxL;
    }
};