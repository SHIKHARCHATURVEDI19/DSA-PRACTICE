3302. Find the Lexicographically Smallest Valid Sequence
Medium
Topics
premium lock icon
Companies
Hint
You are given two strings word1 and word2.

A string x is called almost equal to y if you can change at most one character in x to make it identical to y.

A sequence of indices seq is called valid if:

The indices are sorted in ascending order.
Concatenating the characters at these indices in word1 in the same order results in a string that is almost equal to word2.
Return an array of size word2.length representing the lexicographically smallest valid sequence of indices. If no such sequence of indices exists, return an empty array.

Note that the answer must represent the lexicographically smallest array, not the corresponding string formed by those indices.

 

Example 1:

Input: word1 = "vbcca", word2 = "abc"

Output: [0,1,2]

Explanation:

The lexicographically smallest valid sequence of indices is [0, 1, 2]:

Change word1[0] to 'a'.
word1[1] is already 'b'.
word1[2] is already 'c'.
Example 2:

Input: word1 = "bacdc", word2 = "abc"

Output: [1,2,4]

Explanation:

The lexicographically smallest valid sequence of indices is [1, 2, 4]:

word1[1] is already 'a'.
Change word1[2] to 'b'.
word1[4] is already 'c'.
Example 3:

Input: word1 = "aaaaaa", word2 = "aaabc"

Output: []

Explanation:

There is no valid sequence of indices.

Example 4:

Input: word1 = "abc", word2 = "ab"

Output: [0,1]

 

Constraints:

1 <= word2.length < word1.length <= 3 * 105
word1 and word2 consist only of lowercase English letters.


#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // last_pos[j] stores the maximum starting index in word1 
        // from which word2[j...m-1] can be matched as an EXACT subsequence.
        vector<int> last_pos(m + 1, -1);
        last_pos[m] = n; // Boundary condition

        int ptr = n - 1;
        for (int j = m - 1; j >= 0; --j) {
            while (ptr >= 0 && word1[ptr] != word2[j]) {
                ptr--;
            }
            last_pos[j] = ptr;
            if (ptr >= 0) {
                ptr--; // move to next for previous char in word2
            }
        }

        vector<int> ans;
        bool changed = false;
        int i = 0;

        for (int j = 0; j < m; ++j) {
            // Find the smallest valid index in word1 for word2[j]
            while (i < n) {
                if (word1[i] == word2[j]) {
                    ans.push_back(i);
                    i++;
                    break;
                } else if (!changed && last_pos[j + 1] > i) {
                    // Try using our single allowed change here
                    ans.push_back(i);
                    changed = true;
                    i++;
                    break;
                }
                i++;
            }
        }

        if (ans.size() < m) return {};
        return ans;
    }
};