/*1345. Jump Game IV
Hard

Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
Example 2:

Input: arr = [7]
Output: 0
Explanation: Start index is the last index. You do not need to jump.
Example 3:

Input: arr = [7,6,9,6,9,6,9,7]
Output: 1
Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
 

Constraints:

1 <= arr.length <= 5 * 104
-108 <= arr[i] <= 108*/
/*SOLUTION*/
#include <vector>        // For std::vector
#include <unordered_map> // For std::unordered_map
#include <queue>         // For std::queue

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        // Group all indices by their element values
        unordered_map<int, vector<int>> valueToIndices;
        for (int i = 0; i < n; i++) {
            valueToIndices[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        // Initialize BFS from the first index
        q.push(0);
        visited[0] = true;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            
            while (size--) {
                int curr = q.front();
                q.pop();

                // If we reached the last index, return the steps taken
                if (curr == n - 1) return steps;

                // Option 1: Jump to curr + 1
                if (curr + 1 < n && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }

                // Option 2: Jump to curr - 1
                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }

                // Option 3: Jump to any index j where arr[curr] == arr[j]
                if (valueToIndices.count(arr[curr])) {
                    for (int nextIdx : valueToIndices[arr[curr]]) {
                        if (!visited[nextIdx]) {
                            visited[nextIdx] = true;
                            q.push(nextIdx);
                        }
                    }
                    // CRITICAL OPTIMIZATION: Clear the list to prevent redundant lookups
                    valueToIndices.erase(arr[curr]);
                }
            }
            steps++; // Increment step level after processing current layer
        }

        return -1;
    }
};