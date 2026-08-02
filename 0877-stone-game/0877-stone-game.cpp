class Solution {
public:
int t[501][501];
int solve(int i,int j,vector<int>&piles){
    if(i==j)return piles[i];
    if(t[i][j]!=-1)return t[i][j];
    int takeLeft=piles[i]-solve(i+1,j,piles);
    int takeRight=piles[i]-solve(i,j+1,piles);
    return t[i][j]=max(takeLeft,takeRight);
}
    bool stoneGame(vector<int>& piles) {
    memset(t,-1,sizeof(t));
    return solve(0,0,piles)>0;
    }
};