class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1==s2)return true;
        int n=s1.length();
        for(int i=0;i<n-2;i++){
            if(s1[i]!=s2[i]){
                swap(s1[i],s1[i+2]);
            }
                cout<<s1<<endl;
                cout<<s2<<endl;
                if(s1==s2)return true;
            
        }
        return s1==s2;
    }
};