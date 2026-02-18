class Solution {
public:
bool isPal(int n){
    string s="";
    while(n){
        s.push_back((n&1)+'0');
        n>>=1;
    }
    string b=s;
    reverse(b.begin(),b.end());
    return b==s;
}
    vector<int> minOperations(vector<int>& nums) {
        vector<int> pals;
        for (int i = 0; i < 5001; i++) {
            if (isPal(i))
                pals.push_back(i);
        }
        vector<int> ans;
        for (int num : nums) {
            int best = 1e9;
            for (int x : pals) {
                best = min(best, abs(num - x));
            }
            ans.push_back(best);
        }
        return ans;
    }
};