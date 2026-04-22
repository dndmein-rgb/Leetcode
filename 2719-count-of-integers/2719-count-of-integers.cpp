class Solution {
public:
int mini,maxi;
int M=1e9+7;
int dp[23][2][199];
string substract_one(string& s){
    int n=s.length();
    int i=n-1;
    while(i>=0){
        if(s[i]>'0'){
            s[i]-=1;
            break;
        }else{
            s[i]='9';
            i--;
        }
    }
    if(s[0]=='0' && s.size()>1)return s.substr('1');
    return s;
}
int f(string& s,int idx,bool tight, int sum){
    if(idx==s.size())return (sum>=mini && sum<=maxi);
    if(dp[idx][tight][sum]!=-1)return dp[idx][tight][sum];
    int lb=0;
    int ub=tight?s[idx]-'0':9;
    int res=0;
    for(int dig=lb;dig<=ub;dig++){
        res+=f(s,idx+1,(tight && dig==ub),sum+dig);
        res%=M;
    }
    return dp[idx][tight][sum]= res%M;
}
    int count(string num1, string num2, int min_sum, int max_sum) {
        num1=substract_one(num1);
        mini=min_sum;
        maxi=max_sum;
        memset(dp,-1,sizeof(dp));
        int ans_for_right=f(num2,0,1,0);
         memset(dp,-1,sizeof(dp));
        int ans_for_left=f(num1,0,1,0);
        return (ans_for_right-ans_for_left +M)%M; 
    }
};