3116. Kth Smallest Amount With Single Denomination Combination
Solved
Hard
Topics
premium lock icon
Companies
Hint
You are given an integer array coins representing coins of different denominations and an integer k.

You have an infinite number of coins of each denomination. However, you are not allowed to combine coins of different denominations.

Return the kth smallest amount that can be made using these coins.

 

Example 1:

Input: coins = [3,6,9], k = 3

Output: 9

Explanation: The given coins can make the following amounts:
Coin 3 produces multiples of 3: 3, 6, 9, 12, 15, etc.
Coin 6 produces multiples of 6: 6, 12, 18, 24, etc.
Coin 9 produces multiples of 9: 9, 18, 27, 36, etc.
All of the coins combined produce: 3, 6, 9, 12, 15, etc.

Example 2:

Input: coins = [5,2], k = 7

Output: 12

Explanation: The given coins can make the following amounts:
Coin 5 produces multiples of 5: 5, 10, 15, 20, etc.
Coin 2 produces multiples of 2: 2, 4, 6, 8, 10, 12, etc.
All of the coins combined produce: 2, 4, 5, 6, 8, 10, 12, 14, 15, etc.

 

Constraints:

1 <= coins.length <= 15
1 <= coins[i] <= 25
1 <= k <= 2 * 109
coins contains pairwise distinct integers.

class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / gcd(a, b)) * b;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        int totalSubsets = 1 << n;

        vector<pair<long long, int>> subsetInfo;
        for (int mask = 1; mask < totalSubsets; ++mask) {
            long long currentLcm = 1;
            int bitCount = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    currentLcm = lcm(currentLcm, coins[i]);
                    bitCount++;
                }
            }
            int sign = (bitCount % 2 == 1) ? 1 : -1;
            subsetInfo.push_back({currentLcm, sign});
        }
        auto countMultiples = [&](long long x) -> long long {
            long long count = 0;
            for (const auto& [subsetLcm, sign] : subsetInfo) {
                count += sign * (x / subsetLcm);
            }
            return count;
        };

        long long low = 1;
        long long minCoin = *min_element(coins.begin(), coins.end());
        long long high = minCoin * (long long)k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (countMultiples(mid) >= k) {
                ans = mid;
                high = mid - 1; 
            } else {
                low = mid + 1;
            }
        }

        return ans;
        
    }
};