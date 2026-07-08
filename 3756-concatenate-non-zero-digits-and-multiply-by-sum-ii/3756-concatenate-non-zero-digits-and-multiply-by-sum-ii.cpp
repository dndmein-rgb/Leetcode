class Solution {
public:
vector<int> sumAndMultiply(string s, vector<vector<int>>&q) {
        const int M=1000000007;
        int n=s.size();
        vector<int>p,d;
        for(int i=0;i<n;i++){
          if(s[i]!='0') p.push_back(i),d.push_back(s[i]-'0');
        } 
        int m=d.size(),k=q.size();
        vector<int>ps(m),pv(m),pw(m+1,1),ans(k);
        if(m){
            ps[0]=pv[0]=d[0];
            for(int i=1;i<m;i++){
                ps[i]=ps[i-1]+d[i];
                pv[i]=(int)(((long long)pv[i-1]*10+d[i])%M);
            }
            for(int i=1;i<=m;i++) pw[i]=(int)((long long)pw[i-1]*10%M);
        }
        for(int i=0;i<k;i++){
            int L=q[i][0],R=q[i][1];
            int a=lower_bound(p.begin(),p.end(),L)-p.begin();
            int b=upper_bound(p.begin(),p.end(),R)-p.begin()-1;
            if(a>b){ans[i]=0;continue;}
            long long s2=ps[b]-(a?ps[a-1]:0),v2;
            if(a==0) v2=pv[b];
            else v2=(pv[b]-(long long)pv[a-1]*pw[b-a+1]%M+M)%M;
            ans[i]=(int)(v2*s2%M);
        }
        return ans;
    }
};

 