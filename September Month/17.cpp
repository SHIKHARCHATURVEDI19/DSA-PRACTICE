class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> best(n, INF);

        int left = 0;
        int sum = 0;
        int ans = INF;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            // Shrink window
            while (sum > target) {
                sum -= arr[left++];
            }

            // Carry forward previous best
            if (right > 0)
                best[right] = best[right - 1];

            // Current window has target sum
            if (sum == target) {

                int len = right - left + 1;

                // Need a previous subarray completely before 'left'
                if (left > 0 && best[left - 1] != INF) {
                    ans = min(ans, len + best[left - 1]);
                }

                // Current window can become the best
                best[right] = min(best[right], len);
            }
        }

        return ans == INF ? -1 : ans;
    }
};