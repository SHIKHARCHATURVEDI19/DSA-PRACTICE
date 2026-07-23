
/*3501. Maximize Active Section with Trade II
Hard
Topics
premium lock icon
Companies
Hint
You are given a binary string s of length n, where:

'1' represents an active section.
'0' represents an inactive section.
You can perform at most one trade to maximize the number of active sections in s. In a trade, you:

Convert a contiguous block of '1's that is surrounded by '0's to all '0's.
Afterward, convert a contiguous block of '0's that is surrounded by '1's to all '1's.
Additionally, you are given a 2D array queries, where queries[i] = [li, ri] represents a substring s[li...ri].

For each query, determine the maximum possible number of active sections in s after making the optimal trade on the substring s[li...ri].

Return an array answer, where answer[i] is the result for queries[i].

Note

For each query, treat s[li...ri] as if it is augmented with a '1' at both ends, forming t = '1' + s[li...ri] + '1'. The augmented '1's do not contribute to the final count.
The queries are independent of each other.
 

Example 1:

Input: s = "01", queries = [[0,1]]

Output: [1]

Explanation:

Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 1.

Example 2:

Input: s = "0100", queries = [[0,3],[0,2],[1,3],[2,3]]

Output: [4,3,1,1]

Explanation:

Query [0, 3] → Substring "0100" → Augmented to "101001"
Choose "0100", convert "0100" → "0000" → "1111".
The final string without augmentation is "1111". The maximum number of active sections is 4.

Query [0, 2] → Substring "010" → Augmented to "10101"
Choose "010", convert "010" → "000" → "111".
The final string without augmentation is "1110". The maximum number of active sections is 3.

Query [1, 3] → Substring "100" → Augmented to "11001"
Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 1.

Query [2, 3] → Substring "00" → Augmented to "1001"
Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 1.

Example 3:

Input: s = "1000100", queries = [[1,5],[0,6],[0,4]]

Output: [6,7,2]

Explanation:

Query [1, 5] → Substring "00010" → Augmented to "1000101"
Choose "00010", convert "00010" → "00000" → "11111".
The final string without augmentation is "1111110". The maximum number of active sections is 6.

Query [0, 6] → Substring "1000100" → Augmented to "110001001"
Choose "000100", convert "000100" → "000000" → "111111".
The final string without augmentation is "1111111". The maximum number of active sections is 7.

Query [0, 4] → Substring "10001" → Augmented to "1100011"
Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 2.

Example 4:

Input: s = "01010", queries = [[0,3],[1,4],[1,3]]

Output: [4,4,2]

Explanation:

Query [0, 3] → Substring "0101" → Augmented to "101011"
Choose "010", convert "010" → "000" → "111".
The final string without augmentation is "11110". The maximum number of active sections is 4.

Query [1, 4] → Substring "1010" → Augmented to "110101"
Choose "010", convert "010" → "000" → "111".
The final string without augmentation is "01111". The maximum number of active sections is 4.

Query [1, 3] → Substring "101" → Augmented to "11011"
Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 2.

 

Constraints:

1 <= n == s.length <= 105
1 <= queries.length <= 105
s[i] is either '0' or '1'.
queries[i] = [li, ri]
0 <= li <= ri < n*/

#include <vector>
#include <string>
#include <algorithm>
#include <initializer_list>

using namespace std;

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int total_ones = 0;
        for (char c : s) {
            if (c == '1') total_ones++;
        }

        vector<pair<int, int>> ones;
        int i = 0;
        while (i < n) {
            if (s[i] == '1') {
                int start = i;
                while (i < n && s[i] == '1') i++;
                ones.push_back({start, i - 1});
            } else {
                i++;
            }
        }

        int k = ones.size();
        if (k == 0) {
            return vector<int>(queries.size(), 0);
        }

        vector<pair<int, int>> zeros(k + 1);
        zeros[0] = {0, ones[0].first - 1};
        for (int j = 1; j < k; j++) {
            zeros[j] = {ones[j - 1].second + 1, ones[j].first - 1};
        }
        zeros[k] = {ones[k - 1].second + 1, n - 1};

        auto get_len = [](const pair<int, int>& p) {
            if (p.first > p.second) return 0;
            return p.second - p.first + 1;
        };

        vector<int> V(k);
        for (int j = 0; j < k; j++) {
            V[j] = get_len(zeros[j]) + get_len(zeros[j + 1]);
        }

        int LOGN = 0;
        while ((1 << LOGN) <= k) LOGN++;
        if (LOGN == 0) LOGN = 1;

        vector<vector<int>> st(LOGN, vector<int>(k, 0));
        for (int j = 0; j < k; j++) st[0][j] = V[j];

        for (int j = 1; j < LOGN; j++) {
            for (int idx = 0; idx + (1 << j) <= k; idx++) {
                st[j][idx] = max(st[j - 1][idx], st[j - 1][idx + (1 << (j - 1))]);
            }
        }

        auto query_st = [&](int L, int R) {
            if (L > R) return 0;
            int j = 31 - __builtin_clz(R - L + 1);
            return max(st[j][L], st[j][R - (1 << j) + 1]);
        };

        vector<int> start_I(k), end_I(k);
        for (int j = 0; j < k; j++) {
            start_I[j] = ones[j].first;
            end_I[j] = ones[j].second;
        }

        vector<int> ans(queries.size());

        for (int q = 0; q < (int)queries.size(); q++) {
            int l = queries[q][0];
            int r = queries[q][1];

            int j_start = upper_bound(start_I.begin(), start_I.end(), l) - start_I.begin();
            int j_end = lower_bound(end_I.begin(), end_I.end(), r) - end_I.begin() - 1;

            if (j_start > j_end) {
                ans[q] = total_ones;
            } else if (j_start == j_end) {
                int j = j_start;
                int gain_left = min(get_len(zeros[j]), zeros[j].second - l + 1);
                int gain_right = min(get_len(zeros[j + 1]), r - zeros[j + 1].first + 1);
                ans[q] = total_ones + gain_left + gain_right;
            } else {
            
int z_left_len = max(0, zeros[j_start].second - max(l, zeros[j_start].first) + 1);
int z_right_len = max(0, min(r, zeros[j_end + 1].second) - zeros[j_end + 1].first + 1);

int g1 = z_left_len + get_len(zeros[j_start + 1]);
int g2 = get_len(zeros[j_end]) + z_right_len;
                int g3 = query_st(j_start + 1, j_end - 1);

                int max_gain = max({g1, g2, g3});
                ans[q] = total_ones + max_gain;
            }
        }

        return ans;
    }
};