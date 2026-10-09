class Solution {
public:
bool check(vector<int>&piles,int k,int h){
    long long total=0;
    for(int pile:piles){
        total+=(pile+k-1)/k;
    }
    return total<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int i=1;
        int j=*max_element(piles.begin(),piles.end());
        int ans=j;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(check(piles,mid,h)){
                ans=min(ans,mid);
                j=mid-1;
                }
            else i=mid+1;
        }
        return ans;
    }
};