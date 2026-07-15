class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd=n*n;
        int sumEven=sumOdd+n;

        return __gcd(sumOdd,sumEven);
    }
};