class Solution {
public:

    long long power(long long base, long long exp) {
        long long ans = 1;
        long long MOD = 1000000007;

        while (exp > 0) {

            // If exponent is odd
            if (exp % 2 == 1) {
                ans = (ans * base) % MOD;
            }

            // Square the base
            base = (base * base) % MOD;

            // Divide exponent by 2
            exp /= 2;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {

        long long MOD = 1000000007;

        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;

        long long evenWays = power(5, evenPositions);
        long long oddWays = power(4, oddPositions);

        return (evenWays * oddWays) % MOD;
    }
};