class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t='1'+s+'1';
        int n=t.length();
        vector<pair<char,int>>blocks;
        for(int i=0;i<n;){
            int j=i;
            while(j<n && t[j]==t[i])j++;
            blocks.push_back({t[i],j-i});
            i=j;
        }
        int gain=0;
        for(int i=1;i<blocks.size();i++){
            if(blocks[i].first=='1' && blocks[i-1].first=='0' && blocks[i+1].first=='0'){
                gain=max(gain,blocks[i-1].second+blocks[i+1].second);
            }
        }
        int ones=count(s.begin(),s.end(),'1');
        return gain+ones;

    }
};