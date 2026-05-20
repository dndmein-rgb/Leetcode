class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            unordered_set<int>st;
            int count=0;
            for(int j=0;j<=i;j++){
                st.insert(A[j]);
            }
            for(int j=0;j<=i;j++){
                if(st.count(B[j]))count++;
            }
            ans[i]=count;
        }
        return ans;
    }
};