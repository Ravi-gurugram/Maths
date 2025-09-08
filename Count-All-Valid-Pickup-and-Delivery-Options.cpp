class Solution {
public:
    int countOrders(int n) {
        long long mod = 1e9+7;
        long long ans = 1;

        for (int i = 1; i <= n; i++) {
            ans = ans * i % mod;             // i!
            ans = ans * (2LL * i - 1) % mod; // multiply by odd number
        }
        return ans;
    }
};
