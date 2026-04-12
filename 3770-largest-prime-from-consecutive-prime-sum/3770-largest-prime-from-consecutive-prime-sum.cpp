vector<bool> isPrime;

vector<int> setPrimes() {
    int nMax = 500001;
    isPrime.assign(nMax, true);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < nMax; ++i) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j < nMax; j += i) {
            isPrime[j] = false;
        }
    }

    vector<int> primes;
    for (int i = 2; i < nMax; ++i) {
        if (isPrime[i]) primes.push_back(i);
    }
    return primes;
}

vector<int> primes = setPrimes();

class Solution {
public:
    int largestPrime(int n) {
        if (n < 2) return 0;

        int sum = 0, res = 0;

        for (int p : primes) {
            sum += p;
            if (sum > n) break;
            if (isPrime[sum]) res = sum;
        }
        return res;
    }
};