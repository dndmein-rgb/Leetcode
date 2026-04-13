class Solution {
public:
bool isPal(int x){
    string s;
    while(x){
        s+=((x&1 )+'1');
        x>>=1;
    }
    string b=s;
    reverse(s.begin(),s.end());
    return s==b;
}
    vector<int> minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>palindromes;
        for(int i=0;i<5001;i++){
            if(isPal(i))palindromes.push_back(i);
        }
        vector<int>ans(n,INT_MAX);
        for(int i=0;i<n;i++){
            for(int x:palindromes){
                ans[i]=min(ans[i],abs(nums[i]-x));
            }
        }
        return ans;
    }
};