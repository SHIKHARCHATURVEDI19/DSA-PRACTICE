3734. Lexicographically Smallest Palindromic Permutation Greater Than Target
Hard
Topics
premium lock icon
Companies
Hint
You are given two strings s and target, each of length n, consisting of lowercase English letters.

Return the lexicographically smallest string that is both a palindromic permutation of s and strictly greater than target. If no such permutation exists, return an empty string.

 

Example 1:

Input: s = "baba", target = "abba"

Output: "baab"

Explanation:

The palindromic permutations of s (in lexicographical order) are "abba" and "baab".
The lexicographically smallest permutation that is strictly greater than target is "baab".
Example 2:

Input: s = "baba", target = "bbaa"

Output: ""

Explanation:

The palindromic permutations of s (in lexicographical order) are "abba" and "baab".
None of them is lexicographically strictly greater than target. Therefore, the answer is "".
Example 3:

Input: s = "abc", target = "abb"

Output: ""

Explanation:

s has no palindromic permutations. Therefore, the answer is "".

Example 4:

Input: s = "aac", target = "abb"

Output: "aca"

Explanation:

The only palindromic permutation of s is "aca".
"aca" is strictly greater than target. Therefore, the answer is "aca".
 

Constraints:

1 <= n == s.length == target.length <= 300
s and target consist of only lowercase English letters.29.cpp29


class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int odd_count = 0;
        int odd_char = -1;
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_count++;
                odd_char = i;
            }
        }

        if ((n % 2 == 0 && odd_count > 0) || (n % 2 == 1 && odd_count != 1)) {
            return "";
        }

        vector<int> half_count(26, 0);
        for (int i = 0; i < 26; ++i) {
            half_count[i] = count[i] / 2;
        }

        int m = n / 2;
        string best = "";

        auto build_palindrome = [&](const string& first_half) -> string {
            string full = first_half;
            if (n % 2 == 1) {
                full += (char)('a' + odd_char);
            }
            string second_half = first_half;
            reverse(second_half.begin(), second_half.end());
            full += second_half;
            return full;
        };

        bool can_match_exact = true;
        vector<int> cur_half = half_count;
        string exact_prefix = "";
        for (int i = 0; i < m; ++i) {
            int ch = target[i] - 'a';
            if (cur_half[ch] > 0) {
                cur_half[ch]--;
                exact_prefix += target[i];
            } else {
                can_match_exact = false;
                break;
            }
        }

        if (can_match_exact) {
            string cand = build_palindrome(exact_prefix);
            if (cand > target) {
                best = cand;
            }
        }

        for (int i = m - 1; i >= 0; --i) {
            vector<int> temp_count = half_count;
            bool valid_prefix = true;
            for (int k = 0; k < i; ++k) {
                int ch = target[k] - 'a';
                if (temp_count[ch] > 0) {
                    temp_count[ch]--;
                } else {
                    valid_prefix = false;
                    break;
                }
            }

            if (!valid_prefix) continue;

            for (int c = target[i] - 'a' + 1; c < 26; ++c) {
                if (temp_count[c] > 0) {
                    temp_count[c]--;
                    string first_half = target.substr(0, i);
                    first_half += (char)('a' + c);

                    for (int ch = 0; ch < 26; ++ch) {
                        while (temp_count[ch] > 0) {
                            first_half += (char)('a' + ch);
                            temp_count[ch]--;
                        }
                    }

                    string cand = build_palindrome(first_half);
                    if (best == "" || cand < best) {
                        best = cand;
                    }
                    break;
                }
            }
        }

        return best;
    }
};