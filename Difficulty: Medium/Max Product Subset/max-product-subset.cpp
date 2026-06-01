class Solution {
public:
    long long mod = 1000000007;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    int findMaxProduct(vector<int>& arr) {

        int negCount = 0;
        int zeroCount = 0;
        int maxNegative = INT_MIN;

        for (int x : arr) {
            if (x == 0) zeroCount++;
            else if (x < 0) {
                negCount++;
                maxNegative = max(maxNegative, x);
            }
        }

        int n = arr.size();

        if (n == 1)
            return arr[0];

        if (zeroCount == n)
            return 0;

        if (negCount == 1 && negCount + zeroCount == n)
            return 0;

        long long ans = 1;
        bool skipped = false;

        for (int x : arr) {

            if (x == 0)
                continue;

            if (negCount % 2 == 1 &&
                x == maxNegative &&
                !skipped) {
                skipped = true;
                continue;
            }

            long long val = x;

            if (val < 0)
                val = (val + mod) % mod;

            ans = (ans * val) % mod;
        }

        return ans;
    }
};