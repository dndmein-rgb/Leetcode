class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        int i = 0,result=n, result1 = 0, result2 = 0;
        int j = 0;
        while (j < 2 * n) {
            char expectedCharS1=(j%2)?'1':'0';
            char expectedCharS2=(j%2)?'0':'1';
            if (s[j%n] != expectedCharS1)
                result1++;
            if (s[j%n] != expectedCharS2)
                result2++;
            if (j - i + 1 > n) {
                 expectedCharS1=(i%2)?'1':'0';
             expectedCharS2=(i%2)?'0':'1';
                if (s[i%n] != expectedCharS1)
                    result1--;
                if (s[i%n] != expectedCharS2)
                    result2--;
                i++;
            }
            if (j - i + 1 == n) {
                result = min({result, result1, result2});
            }
            j++;
        }
        return result;
    }
};