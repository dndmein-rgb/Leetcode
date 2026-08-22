class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            int digit = n % 10;
            sum += digit;
            n /= 10;
        }
        return sum;
    }

    int digitProd(int n) {
        int prod = 1;
        while (n) {
            int digit = n % 10;
            prod *= digit;
            n /= 10;
        }
        return prod;
    }
    bool checkDivisibility(int n) {
        int sum = digitSum(n);
        int product = digitProd(n);
       int total = sum + product;
        return n % total == 0;
    }
};