class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int>freq; //num,count
        for(int x:nums){
            freq[x]++;
        }
        int ans=1;
        if(freq.count(1)){
            ans=(freq[1]%2==0 ?freq[1]-1 :freq[1]);
        }
        for(auto& [num,count]:freq){
            if(num==1)continue;
            int len=1;
        long long curr=num;
        while(freq[curr]>=2){
             if (curr > 1000000000LL / curr) break;
        long long next=curr*curr;
            if(!freq.count(next))break;
            len+=2;
            curr=next;
        }
        ans=max(ans,len);
        }
        return ans;
    }
};