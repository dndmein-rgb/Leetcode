class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string>st;
        for(int a:arr1){
            string s=to_string(a);
            for(int i=0;i<s.length();i++){
                int j=0;
                    st.insert(s.substr(j,i-j+1));
                
            }
            
        }
        int longest=0;
        for(int a:arr2){
            string s=to_string(a);
            for(int i=0;i<s.length();i++){
                int j=0;
                    if(st.count(s.substr(j,i-j+1))){
                        longest=max(longest,i-j+1);
                    }
                
            }

        }
        return longest;
    }
};