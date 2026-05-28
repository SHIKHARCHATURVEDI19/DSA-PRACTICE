/*3093. Longest Common Suffix Queries
Hard
Topics
premium lock icon
Companies
Hint
You are given two arrays of strings wordsContainer and wordsQuery.

For each wordsQuery[i], you need to find a string from wordsContainer that has the longest common suffix with wordsQuery[i]. If there are two or more strings in wordsContainer that share the longest common suffix, find the string that is the smallest in length. If there are two or more such strings that have the same smallest length, find the one that occurred earlier in wordsContainer.

Return an array of integers ans, where ans[i] is the index of the string in wordsContainer that has the longest common suffix with wordsQuery[i].

 

Example 1:

Input: wordsContainer = ["abcd","bcd","xbcd"], wordsQuery = ["cd","bcd","xyz"]

Output: [1,1,1]

Explanation:

Let's look at each wordsQuery[i] separately:

For wordsQuery[0] = "cd", strings from wordsContainer that share the longest common suffix "cd" are at indices 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
For wordsQuery[1] = "bcd", strings from wordsContainer that share the longest common suffix "bcd" are at indices 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
For wordsQuery[2] = "xyz", there is no string from wordsContainer that shares a common suffix. Hence the longest common suffix is "", that is shared with strings at index 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
Example 2:

Input: wordsContainer = ["abcdefgh","poiuygh","ghghgh"], wordsQuery = ["gh","acbfgh","acbfegh"]

Output: [2,0,2]

Explanation:

Let's look at each wordsQuery[i] separately:

For wordsQuery[0] = "gh", strings from wordsContainer that share the longest common suffix "gh" are at indices 0, 1, and 2. Among these, the answer is the string at index 2 because it has the shortest length of 6.
For wordsQuery[1] = "acbfgh", only the string at index 0 shares the longest common suffix "fgh". Hence it is the answer, even though the string at index 2 is shorter.
For wordsQuery[2] = "acbfegh", strings from wordsContainer that share the longest common suffix "gh" are at indices 0, 1, and 2. Among these, the answer is the string at index 2 because it has the shortest length of 6.
 

Constraints:

1 <= wordsContainer.length, wordsQuery.length <= 104
1 <= wordsContainer[i].length <= 5 * 103
1 <= wordsQuery[i].length <= 5 * 103
wordsContainer[i] consists only of lowercase English letters.
wordsQuery[i] consists only of lowercase English letters.
Sum of wordsContainer[i].length is at most 5 * 105.
Sum of wordsQuery[i].length is at most 5 * 105.

SOLUTION*/
#include <vector>
#include <string>

using namespace std;

// Using a flat structure with integers instead of pointers to save memory
struct FlatNode {
    int children[26];
    int bestIndex;

    FlatNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = -1; // -1 means no child node exists
        }
        bestIndex = -1;
    }
};

class Solution {
private:
    vector<FlatNode> trie;

    bool isBetter(int currIdx, int bestIdx, const vector<string>& words) {
        if (bestIdx == -1) return true;
        if (words[currIdx].size() < words[bestIdx].size()) return true;
        if (words[currIdx].size() == words[bestIdx].size()) return currIdx < bestIdx;
        return false;
    }

    void insert(const string& word, int wordIdx, const vector<string>& words) {
        int curr = 0; // Start at the root node (index 0)
        
        if (isBetter(wordIdx, trie[curr].bestIndex, words)) {
            trie[curr].bestIndex = wordIdx;
        }

        for (int i = word.size() - 1; i >= 0; --i) {
            int charIdx = word[i] - 'a';
            if (trie[curr].children[charIdx] == -1) {
                trie.emplace_back(); // Create a new node in the vector
                trie[curr].children[charIdx] = trie.size() - 1;
            }
            curr = trie[curr].children[charIdx];

            if (isBetter(wordIdx, trie[curr].bestIndex, words)) {
                trie[curr].bestIndex = wordIdx;
            }
        }
    }

    int search(const string& query) {
        int curr = 0;
        int lastValidIndex = trie[0].bestIndex;

        for (int i = query.size() - 1; i >= 0; --i) {
            int charIdx = query[i] - 'a';
            if (trie[curr].children[charIdx] == -1) {
                break;
            }
            curr = trie[curr].children[charIdx];
            lastValidIndex = trie[curr].bestIndex;
        }
        return lastValidIndex;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        // Clear and initialize the trie with a root node
        trie.clear();
        trie.emplace_back(); 

        for (int i = 0; i < wordsContainer.size(); ++i) {
            insert(wordsContainer[i], i, wordsContainer);
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size()); // Small optimization to prevent reallocations
        for (const string& query : wordsQuery) {
            ans.push_back(search(query));
        }

        return ans;
    }
};