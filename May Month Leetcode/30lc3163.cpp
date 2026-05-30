/*3161. Block Placement Queries
Solved
Hard
Topics
premium lock icon
Companies
Hint
There exists an infinite number line, with its origin at 0 and extending towards the positive x-axis.

You are given a 2D array queries, which contains two types of queries:

For a query of type 1, queries[i] = [1, x]. Build an obstacle at distance x from the origin. It is guaranteed that there is no obstacle at distance x when the query is asked.
For a query of type 2, queries[i] = [2, x, sz]. Check if it is possible to place a block of size sz anywhere in the range [0, x] on the line, such that the block entirely lies in the range [0, x]. A block cannot be placed if it intersects with any obstacle, but it may touch it. Note that you do not actually place the block. Queries are separate.
Return a boolean array results, where results[i] is true if you can place the block specified in the ith query of type 2, and false otherwise.

 

Example 1:

Input: queries = [[1,2],[2,3,3],[2,3,1],[2,2,2]]

Output: [false,true,true]

Explanation:



For query 0, place an obstacle at x = 2. A block of size at most 2 can be placed before x = 3.

Example 2:

Input: queries = [[1,7],[2,7,6],[1,2],[2,7,5],[2,7,6]]

Output: [true,true,false]

Explanation:



Place an obstacle at x = 7 for query 0. A block of size at most 7 can be placed before x = 7.
Place an obstacle at x = 2 for query 2. Now, a block of size at most 5 can be placed before x = 7, and a block of size at most 2 before x = 2.
 

Constraints:

1 <= queries.length <= 15 * 104
2 <= queries[i].length <= 3
1 <= queries[i][0] <= 2
1 <= x, sz <= min(5 * 104, 3 * queries.length)
The input is generated such that for queries of type 1, no obstacle exists at distance x when the query is asked.
The input is generated such that there is at least one query of type 2.

SOLUTION*/

#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
    int tree[200005]; // Flat array segment tree layout
    int n;

    void update(int idx, int val) {
        idx += n;
        tree[idx] = val;
        for (idx >>= 1; idx > 0; idx >>= 1) {
            tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
        }
    }

    int query(int l, int r) {
        int res = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, tree[l++]);
            if (r & 1) res = max(res, tree[--r]);
        }
        return res;
    }

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int max_x = 0;
        for (const auto& q : queries) max_x = max(max_x, q[1]);
        
        n = max_x + 2;
        fill(tree, tree + 2 * n, 0);

        set<int> obstacles = {0, max_x + 1};
        update(0, max_x + 1); // Initial full gap

        vector<bool> results;

        for (const auto& q : queries) {
            int type = q[0], x = q[1];
            auto it = obstacles.upper_bound(x);

            if (type == 1) {
                if (obstacles.count(x)) continue; // Skip if already exists
                int r = *it, l = *prev(it);
                obstacles.insert(x);
                
                // Properly overwrite old gap sizes with the new smaller splits
                update(l, x - l);
                update(x, r - x);
            } else {
                int sz = q[2];
                int l = *prev(it);
                
                // Query max gap in [0, l-1] and compare with trailing [l, x]
                if (max(query(0, l - 1), x - l) >= sz) {
                    results.push_back(true);
                } else {
                    results.push_back(false);
                }
            }
        }
        return results;
    }
};