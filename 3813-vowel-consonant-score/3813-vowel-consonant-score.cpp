class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0, cons = 0;
        
        for (char ch : s) {
            if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
                v++;
            else if(!isdigit(ch) && ch!=' ')
                cons++;
        }
        
        return cons > 0 ? v / cons : 0;
    }
};
