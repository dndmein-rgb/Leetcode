class Solution {
public:
    long long countCommas(long long n) {
      long long total_commas = 0;
        long long threshold = 1000;

        // Loop through each "comma level" (thousands, millions, billions...)
        // We use a check to prevent threshold overflow if n is near LLONG_MAX
        while (n >= threshold) {
            total_commas += (n - threshold + 1);
            
            // Check if multiplying by 1000 will overflow before doing it
            if (threshold > 2e15) break; 
            threshold *= 1000;
        }

        return total_commas;
    }
};