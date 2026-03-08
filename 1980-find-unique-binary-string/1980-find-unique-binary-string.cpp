class Solution {
public:
    int binaryToDecimal(string s){
        int num = 0;
        for(char c : s){
            num = num*2 + (c-'0');
        }
        return num;
    }

    string decToBinary(int n, int bits){
        string s;
        while(n){
            s.push_back(n%2 + '0');
            n/=2;
        }
        while(s.size() < bits) s.push_back('0');
        reverse(s.begin(), s.end());
        return s;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        vector<bool> vis(1<<n,false);

        for(auto &s:nums){
            int value=binaryToDecimal(s);
            vis[value]=true;
        }

        int ans=0;
        for(int i=0;i<(1<<n);i++){
            if(!vis[i]){
                ans=i;
                break;
            }
        }

        return decToBinary(ans,n);
    }
};