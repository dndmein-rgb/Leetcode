class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>seen(nums.begin(),nums.end());
        int multiple=k;
        while(true){
            if(!seen.count(multiple))
                return multiple;
            multiple+=k;
        }
    }
};