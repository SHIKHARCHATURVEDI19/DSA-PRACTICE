3534. Path Existence Queries in a Graph II
Solved
Hard
Topics
premium lock icon
Companies
Hint
You are given an integer n representing the number of nodes in a graph, labeled from 0 to n - 1.

You are also given an integer array nums of length n and an integer maxDiff.

An undirected edge exists between nodes i and j if the absolute difference between nums[i] and nums[j] is at most maxDiff (i.e., |nums[i] - nums[j]| <= maxDiff).

You are also given a 2D integer array queries. For each queries[i] = [ui, vi], find the minimum distance between nodes ui and vi. If no path exists between the two nodes, return -1 for that query.

Return an array answer, where answer[i] is the result of the ith query.

Note: The edges between the nodes are unweighted.

 

Example 1:

Input: n = 5, nums = [1,8,3,4,2], maxDiff = 3, queries = [[0,3],[2,4]]

Output: [1,1]

Explanation:

The resulting graph is:



Query	Shortest Path	Minimum Distance
[0, 3]	0 → 3	1
[2, 4]	2 → 4	1
Thus, the output is [1, 1].

Example 2:

Input: n = 5, nums = [5,3,1,9,10], maxDiff = 2, queries = [[0,1],[0,2],[2,3],[4,3]]

Output: [1,2,-1,1]

Explanation:

The resulting graph is:



Query	Shortest Path	Minimum Distance
[0, 1]	0 → 1	1
[0, 2]	0 → 1 → 2	2
[2, 3]	None	-1
[4, 3]	3 → 4	1
Thus, the output is [1, 2, -1, 1].

Example 3:

Input: n = 3, nums = [3,6,1], maxDiff = 1, queries = [[0,0],[0,1],[1,2]]

Output: [0,-1,-1]

Explanation:

There are no edges between any two nodes because:

Nodes 0 and 1: |nums[0] - nums[1]| = |3 - 6| = 3 > 1
Nodes 0 and 2: |nums[0] - nums[2]| = |3 - 1| = 2 > 1
Nodes 1 and 2: |nums[1] - nums[2]| = |6 - 1| = 5 > 1
Thus, no node can reach any other node, and the output is [0, -1, -1].

 

Constraints:

1 <= n == nums.length <= 105
0 <= nums[i] <= 105
0 <= maxDiff <= 105
1 <= queries.length <= 105
queries[i] == [ui, vi]
0 <= ui, vi < n


class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> sortedNums;
        vector<int> indexMap(n);
        vector<pair<int, int>> sortedNumAndIndexes;

        for (int i = 0; i < n; ++i)
            sortedNumAndIndexes.emplace_back(nums[i], i);

        sort(sortedNumAndIndexes.begin(), sortedNumAndIndexes.end());

        for (int i = 0; i < n; ++i) {
            auto [num, originalIndex] = sortedNumAndIndexes[i];
            sortedNums.push_back(num);
            indexMap[originalIndex] = i;
        }

        int maxLevel = 0;
        while ((1 << maxLevel) <= n) maxLevel++;
        maxLevel++;

        vector<vector<int>> jump(n, vector<int>(maxLevel));

        int right = 0;
        for (int i = 0; i < n; ++i) {
            while (right + 1 < n && sortedNums[right + 1] - sortedNums[i] <= maxDiff)
                right++;
            jump[i][0] = right;
        }

        for (int level = 1; level < maxLevel; ++level) {
            for (int i = 0; i < n; ++i) {
                jump[i][level] = jump[jump[i][level - 1]][level - 1];
            }
        }

        for (auto &q : queries) {
            int u = indexMap[q[0]];
            int v = indexMap[q[1]];

            int start = min(u, v);
            int end = max(u, v);

            int res = minJumps(jump, start, end, maxLevel - 1);
            ans.push_back(res == INT_MAX ? -1 : res);
        }

        return ans;
    }

private:
    int minJumps(vector<vector<int>>& jump, int start, int end, int level) {
        if (start == end)
            return 0;

        if (jump[start][0] >= end)
            return 1;

        if (jump[start][level] < end)
            return INT_MAX;

        int j = level;
        while (j >= 0 && jump[start][j] >= end)
            j--;

        return (1 << j) + minJumps(jump, jump[start][j], end, j);
    }
};