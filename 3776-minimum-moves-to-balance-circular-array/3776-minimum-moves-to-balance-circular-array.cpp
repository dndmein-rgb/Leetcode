class Solution {
public:
typedef long long ll;
    long long minMoves(vector<int>& balance) {
        int n=balance.size();
        ll culprit=-1;
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=balance[i];
            if(balance[i]<0){
                culprit=i;
            }
        }
        if(sum<0)return -1;
        if(culprit==-1)return 0;
        ll moves=0;
        ll distance=1;
        while(balance[culprit]<0){
            ll left=(culprit-distance+n)%n;
            ll right=(culprit+distance)%n;
            ll total=balance[left]+balance[right];
            if(left==right)total-=balance[left];
            ll need=-balance[culprit];
            ll taken=min(need,total);
            moves+=(distance*taken);
            balance[culprit]+=taken;
            distance++;
        }
        return moves;

    }
};