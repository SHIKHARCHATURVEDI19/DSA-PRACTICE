/*1301. Number of Paths with Max Score
Solved
Hard
Topics
premium lock icon
Companies
Hint
You are given a square board of characters. You can move on the board starting at the bottom right square marked with the character 'S'.

You need to reach the top left square marked with the character 'E'. The rest of the squares are labeled either with a numeric character 1, 2, ..., 9 or with an obstacle 'X'. In one move you can go up, left or up-left (diagonally) only if there is no obstacle there.

Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum, taken modulo 10^9 + 7.

In case there is no path, return [0, 0].

 

Example 1:

Input: board = ["E23","2X2","12S"]
Output: [7,1]
Example 2:

Input: board = ["E12","1X1","21S"]
Output: [4,2]
Example 3:

Input: board = ["E11","XXX","11S"]
Output: [0,0]
 

Constraints:

2 <= board.length == board[i].length <= 100*/


#include <vector>
#include <string>
uisng namespace std;
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;
        
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {0, 0}));
        dp[0][0] = {0, 1};
        
        int dirs[3][2] = {{-1, 0}, {0, -1}, {-1, -1}};
        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if ((r == 0 && c == 0) || board[r][c] == 'X') continue;
                
                int max_prev_score = -1;
                long long total_paths = 0;
                
                for (auto& dir : dirs) {
                    int prev_r = r + dir[0];
                    int prev_c = c + dir[1];
                    
                    if (prev_r >= 0 && prev_c >= 0 && dp[prev_r][prev_c].second > 0) {
                        int prev_score = dp[prev_r][prev_c].first;
                        
                        if (prev_score > max_prev_score) {
                            max_prev_score = prev_score;
                            total_paths = dp[prev_r][prev_c].second;
                        } else if (prev_score == max_prev_score) {
                            total_paths = (total_paths + dp[prev_r][prev_c].second) % MOD;
                        }
                    }
                }
                
                if (max_prev_score != -1) {
                    int curr_val = (board[r][c] == 'S') ? 0 : (board[r][c] - '0');
                    dp[r][c] = {max_prev_score + curr_val, total_paths};
                }
            }
        }
        
        return {dp[n-1][n-1].first, dp[n-1][n-1].second};
    }
};