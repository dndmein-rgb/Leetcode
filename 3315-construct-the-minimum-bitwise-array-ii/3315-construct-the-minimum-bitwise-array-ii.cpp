class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
          int n=nums.size();
        vector<int>ans;
        for(int num:nums){
            if(num==2){
                ans.push_back(-1);
                continue;
                }
                 bool found=false;
            for(int i=1;i<32;i++ ){
                if((num&(1<<i))>0)continue;
   
                ans.push_back((num^(1<<(i-1))));
                found=true;
                break;

            }
            if(!found)ans.push_back(-1);
        }
        return ans;
    }
    
};