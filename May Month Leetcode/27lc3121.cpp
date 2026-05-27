/*3121. Count the Number of Special Characters II
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence of c.

Return the number of special letters in word.

 

Example 1:

Input: word = "aaAbcBC"

Output: 3

Explanation:

The special characters are 'a', 'b', and 'c'.

Example 2:

Input: word = "abc"

Output: 0

Explanation:

There are no special characters in word.

Example 3:

Input: word = "AbBCab"

Output: 0

Explanation:

There are no special characters in word.

 

Constraints:

1 <= word.length <= 2 * 105
word consists of only lowercase and uppercase English letters.

SOLUTION*/

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLower(26, -1);   // last index of lowercase
        vector<int> firstUpper(26, -1);  // first index of uppercase

        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (islower(ch)) {
                lastLower[ch - 'a'] = i;  // update last lowercase occurrence
            } else {
                if (firstUpper[ch - 'A'] == -1) {
                    firstUpper[ch - 'A'] = i;  // record first uppercase occurrence
                }
            }
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (lastLower[i] != -1 && firstUpper[i] != -1 && lastLower[i] < firstUpper[i]) {
                count++;
            }
        }
        return count;
    }
};
