2472. Maximum Number of Non-overlapping Palindrome Substrings
Solved
Hard
Topics
premium lock icon
Companies
Hint
You are given a string s and a positive integer k.

Select a set of non-overlapping substrings from the string s that satisfy the following conditions:

The length of each substring is at least k.
Each substring is a palindrome.
Return the maximum number of substrings in an optimal selection.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "abaccdbbd", k = 3
Output: 2
Explanation: We can select the substrings underlined in s = "abaccdbbd". Both "aba" and "dbbd" are palindromes and have a length of at least k = 3.
It can be shown that we cannot find a selection with more than two valid substrings.
Example 2:

Input: s = "adbcda", k = 2
Output: 0
Explanation: There is no palindrome substring of length at least 2 in the string.
 

Constraints:

1 <= k <= s.length <= 2000
s consists of lowercase English letters.



class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int count = 0;
        int lastEnd = -1; // End index of the last selected non-overlapping palindrome

        for (int i = 0; i < 2 * n - 1; ++i) {
            int left = i / 2;
            int right = left + (i % 2);

            while (left >= 0 && right < n && s[left] == s[right]) {
                // If expansion starts before or at the last picked palindrome's end, stop
                if (left <= lastEnd) {
                    break;
                }

                int len = right - left + 1;
                if (len >= k) {
                    // Found a valid palindrome of length k or k + 1
                    count++;
                    lastEnd = right;
                    break; // Move to the next center
                }

                left--;
                right++;
            }
        }

        return count;
    }
};