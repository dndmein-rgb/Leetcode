class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>freq1(256,0),freq2(256,0);
        for(char c:s1){
            freq1[c]++;
        }
        int n=s1.length();
        int m=s2.length();

        int i=0,j=0;
        while(j<m){
            freq2[s2[j]]++;
            while(j-i+1>n){
                freq2[s2[i]]--;
                i++;
            }
            if(j-i+1==n){
                if(freq1==freq2)return true;

            }
            j++;
        }
        return false;
    }
};