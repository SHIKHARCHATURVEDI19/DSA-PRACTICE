3518. Smallest Palindromic Rearrangement II
Hard
Topics
premium lock icon
Companies
Hint
You are given a palindromic string s and an integer k.

Return the k-th lexicographically smallest palindromic permutation of s. If there are fewer than k distinct palindromic permutations, return an empty string.

Note: Different rearrangements that yield the same palindromic string are considered identical and are counted once.

 

Example 1:

Input: s = "abba", k = 2

Output: "baab"

Explanation:

The two distinct palindromic rearrangements of "abba" are "abba" and "baab".
Lexicographically, "abba" comes before "baab". Since k = 2, the output is "baab".
Example 2:

Input: s = "aa", k = 2

Output: ""

Explanation:

There is only one palindromic rearrangement: "aa".
The output is an empty string since k = 2 exceeds the number of possible rearrangements.
Example 3:

Input: s = "bacab", k = 1

Output: "abcba"

Explanation:

The two distinct palindromic rearrangements of "bacab" are "abcba" and "bacab".
Lexicographically, "abcba" comes before "bacab". Since k = 1, the output is "abcba".
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
s is guaranteed to be palindromic.
1 <= k <= 106

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    const long long INF = 1e12;

    long long countPermutations(const vector<int>& counts, int total) {
        long long res = 1;
        int current_n = total;

        for (int count : counts) {
            if (count == 0) continue;
            for (int j = 1; j <= count; ++j) {
                res = res * current_n / j;
                current_n--;
                if (res > INF) res = INF;
            }
        }
        return res;
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<int> half_cnt(26, 0);
        char mid_char = 0;
        for (int i = 0; i < 26; ++i) {
            half_cnt[i] = freq[i] / 2;
            if (freq[i] % 2 != 0) {
                mid_char = 'a' + i;
            }
        }

        int half_len = n / 2;

        long long total_arrangements = countPermutations(half_cnt, half_len);
        if (total_arrangements < k) {
            return "";
        }

        string first_half = "";
        long long current_k = k;

        for (int i = 0; i < half_len; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (half_cnt[c] == 0) continue;

                half_cnt[c]--;
                long long ways = countPermutations(half_cnt, half_len - 1 - i);

                if (current_k <= ways) {
                    first_half += (char)('a' + c);
                    break;
                } else {
                    current_k -= ways;
                    half_cnt[c]++;
                }
            }
        }

        string second_half = first_half;
        reverse(second_half.begin(), second_half.end());

        if (n % 2 != 0) {
            return first_half + mid_char + second_half;
        } else {
            return first_half + second_half;
        }
    }
};