class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0, cons = 0;
        
        for (char ch : s) {
            if(isalpha(ch)){
            if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
                v++;
            else 
                cons++;
        }
        }
        
        return cons > 0 ? v / cons : 0;
    }
};
