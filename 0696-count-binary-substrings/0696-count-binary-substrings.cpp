class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.length();
        vector<int>ans;
        char curr=s[0];
        int counter=1;
        for(int i=1;i<n;i++){
            if(s[i]==curr){
                counter++;
            }else {
                curr=s[i];
                ans.push_back(counter);
                counter=1;
            }
        }
            ans.push_back(counter);
        int total=0;
        for(int i=0;i<ans.size()-1;i++){
            total+=min(ans[i],ans[i+1]);
        }
        return total;
    }
};