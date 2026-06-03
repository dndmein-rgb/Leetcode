class Solution {
public:
unordered_set<string>st;
int t[301];
int n;
bool solve(int i,vector<string>&wordDict,string&s){
    if(i==n)return true;
    if(t[i]!=-1)return t[i];
    string curr="";
    for(int j=i;j<n;j++){
        curr.push_back(s[j]);
        if(st.count(curr)){
            if(solve(j+1,wordDict,s))return t[i]=true;
        }
    }
    return t[i]=false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.length();
        st.insert(wordDict.begin(),wordDict.end());
        memset(t,-1,sizeof(t));
        return solve(0,wordDict,s);
    }
};