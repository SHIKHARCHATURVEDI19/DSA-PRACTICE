3720. Lexicographically Smallest Permutation Greater Than Target
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given two strings s and target, both having length n, consisting of lowercase English letters.

Return the lexicographically smallest permutation of s that is strictly greater than target. If no permutation of s is lexicographically strictly greater than target, return an empty string.

A string a is lexicographically strictly greater than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b.

 

Example 1:

Input: s = "abc", target = "bba"

Output: "bca"

Explanation:

The permutations of s (in lexicographical order) are "abc", "acb", "bac", "bca", "cab", and "cba".
The lexicographically smallest permutation that is strictly greater than target is "bca".
Example 2:

Input: s = "leet", target = "code"

Output: "eelt"

Explanation:

The permutations of s (in lexicographical order) are "eelt", "eetl", "elet", "elte", "etel", "etle", "leet", "lete", "ltee", "teel", "tele", and "tlee".
The lexicographically smallest permutation that is strictly greater than target is "eelt".
Example 3:

Input: s = "baba", target = "bbaa"

Output: ""

Explanation:

The permutations of s (in lexicographical order) are "aabb", "abab", "abba", "baab", "baba", and "bbaa".
None of them is lexicographically strictly greater than target. Therefore, the answer is "".
 

Constraints:

1 <= s.length == target.length <= 300
s and target consist of only lowercase English letters.



class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        vector<int> temp_count = count;
        int max_prefix = 0;
        while (max_prefix < n && temp_count[target[max_prefix] - 'a'] > 0) {
            temp_count[target[max_prefix] - 'a']--;
            max_prefix++;
        }

        for (int i = min(n - 1, max_prefix); i >= 0; --i) {
            vector<int> cur_count = count;
            for (int k = 0; k < i; ++k) {
                cur_count[target[k] - 'a']--;
            }

            for (int c = target[i] - 'a' + 1; c < 26; ++c) {
                if (cur_count[c] > 0) {
                    cur_count[c]--;
                    
                    string res = target.substr(0, i);
                    res.push_back('a' + c);

                    for (int rem = 0; rem < 26; ++rem) {
                        res.append(cur_count[rem], 'a' + rem);
                    }
                    return res;
                }
            }
        }

        return "";
    }
};