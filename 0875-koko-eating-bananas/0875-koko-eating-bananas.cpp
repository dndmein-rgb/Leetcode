class Solution {
public:
bool check (vector<int>&piles,int h,int mid){
    long long total=0;
    for(int p:piles){
        total+=(p+mid-1)/mid;
    }
    return total<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
       int n=piles.size() ;
       int i=1;
       int j=*max_element(piles.begin(),piles.end());
       int ans=INT_MAX;
       while(i<=j){
        int mid=i+(j-i)/2;
        if(check(piles,h,mid)){
            ans=min(ans,mid);
            j=mid-1;
        }else i=mid+1;
       }
       return ans;
    }
};