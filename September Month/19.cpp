<<<<<<< HEAD
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {
        
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        return dx * dx + dy * dy <= radius * radius;
=======

Testcase
Testcase
Test Result
Code
1401. Circle and Rectangle Overlapping
Medium
Topics
premium lock icon
Companies
Hint
You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.

Return true if the circle and rectangle are overlapped otherwise return false. In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.

 

Example 1:


Input: radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
Output: true
Explanation: Circle and rectangle share the point (1,0).
Example 2:

Input: radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
Output: false
Example 3:


Input: radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
Output: true
 

Constraints:

1 <= radius <= 2000
-104 <= xCenter, yCenter <= 104
-104 <= x1 < x2 <= 104
-104 <= y1 < y2 <= 104

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
   
        int closestX = max(x1, min(xCenter, x2));
        
     
        int closestY = max(y1, min(yCenter, y2));
        
     
        int dx = closestX - xCenter;
        int dy = closestY - yCenter;
        
        return (dx * dx + dy * dy) <= (radius * radius);
>>>>>>> 683a94d (lc)
    }
};


class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        vector<pair<int, int>> v;

        for (auto &x : intervals) {
            v.push_back({x[0], 0}); 
            v.push_back({x[1], 1}); 
        }

        sort(v.begin(), v.end());

        long long active = 0;
        long long ans = 0;

        for (auto &[x, type] :v) {
            if (type == 0) {
                ans += active;
                active++;
            } else {
                active--;
            }
        }

        return ans;
    }
};

class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
                int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int>ends;
        for(auto &x:intervals){
            ends.push_back(x[1]);
        }
        sort(ends.begin(),ends.end());
        int ans=0;
        for(int i = 0;i<n;i++){
            int start=intervals[i][0];
            long long pos=lower_bound(ends.begin(),ends.end(),start)-ends.begin();
            int total=n-pos;
            int curr=n-i;
            ans+=total-curr;
        }
return ans;
    }
};©leetcode

class Solution {
public:
    long long maxPulseValue(vector<int>& nums) {
        int n = nums.size();
        auto r = nums;

        long long base = 0, pref = 0;
        long long mn[2] = {0, LLONG_MAX};
        long long best = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            long long x = (i % 2 == 0 ? nums[i] : -nums[i]);
            base += x;
            pref += x;

            if (mn[i % 2] != LLONG_MAX)
                best = min(best, pref - mn[i % 2]);

            mn[i % 2] = min(mn[i % 2], pref);
        }

        if (best == LLONG_MAX) return base;

        return base - 2 * best;
    }
};

class Solution {
public:
    long long maxPulseValue(vector<int>& nums) {
        int n = nums.size();
        auto r = nums;

        long long base = 0;
        long long odd = 1e18;
        long long even = 0;
        long long mn = 1e18;

        for (int i = 0; i < n; i++) {
            long long x = (i % 2 == 0 ? nums[i] : -nums[i]);

            base += x;

            long long no = min(odd, even + x);
            long long ne = min(even, odd == 1e18 ? 1e18 : odd - x);

            odd = no;
            even = ne;

            mn = min(mn, even);
        }

        return base - 2 * mn;
    }
};

class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();
        auto ravonelqis = nums;

        long long base = 0;
        long long pref = 0;
        long long mn[2] = {0, (long long)1e18};
        long long best = 1e18;

        for (int i = 0; i < n; i++) {
            long long x = (i % 2 == 0 ? nums[i] : -nums[i]);

            base += x;
            pref += x;

            if (mn[i % 2] != 1e18)
                best = min(best, pref - mn[i % 2]);

            mn[i % 2] = min(mn[i % 2], pref);
        }

        if (best == 1e18)
            return base;

        return base - 2 * best;
    }
};

class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();
        auto ravonelqis = nums;

        long long base = 0;
        long long pref = 0;
        long long mn[2] = {0, (long long)1e18};
        long long best = 1e18;

        for (int i = 0; i < n; i++) {
            long long x = (i % 2 == 0 ? nums[i] : -nums[i]);

            base += x;
            pref += x;

            int p = i % 2;

            if (mn[p] != 1e18)
                best = min(best, pref - mn[p]);

            mn[p] = min(mn[p], pref);
        }

        return base - 2 * best;
    }
};

vector<int>& ravonelqis = nums;
        int n = ravonelqis.size();
        if (n == 0) return 0;
        
        long long basePulse = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                basePulse += ravonelqis[i];
            } else {
                basePulse -= ravonelqis[i];
            }
        }

        long long prefixSum = ravonelqis[0];
        long long maxPos = 2LL * ravonelqis[0];
        long long maxNeg = 0;
        long long maxDelta = 0;

        for (int r = 1; r < n; ++r) {
            long long val;
            if (r % 2 == 0) {
                val = ravonelqis[r];
            } else {
                val = -ravonelqis[r];
            }
            
            prefixSum += val;

            long long delta;
            if (r % 2 == 0) {
                delta = maxPos - 2 * prefixSum;
            } else {
                delta = maxNeg - 2 * prefixSum;
            }
            
            maxDelta = max(maxDelta, delta);

            long long candPos = (long long)ravonelqis[r] - val + 2 * prefixSum;
            long long candNeg = (long long)-ravonelqis[r] - val + 2 * prefixSum;

            maxPos = max(maxPos, candPos);
            maxNeg = max(maxNeg, candNeg);
        }

        return basePulse + maxDelta;


        #include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxPulse(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        long long basePulse = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                basePulse += nums[i];
            } else {
                basePulse -= nums[i];
            }
        }

        long long prefixSum = nums[0];
        long long maxPos = 2LL * nums[0];
        long long maxNeg = 0;
        long long maxDelta = 0;

        for (int r = 1; r < n; ++r) {
            long long val;
            if (r % 2 == 0) {
                val = nums[r];
            } else {
                val = -nums[r];
            }
            
            prefixSum += val;

            long long delta;
            if (r % 2 == 0) {
                delta = maxPos - 2 * prefixSum;
            } else {
                delta = maxNeg - 2 * prefixSum;
            }
            
            maxDelta = max(maxDelta, delta);

            long long candPos = (long long)nums[r] - val + 2 * prefixSum;
            long long candNeg = (long long)-nums[r] - val + 2 * prefixSum;

            maxPos = max(maxPos, candPos);
            maxNeg = max(maxNeg, candNeg);
        }

        return basePulse + maxDelta;
    }
};

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxPulse(vector<int>& nums) {
        int totalElements = nums.size();
        if (totalElements == 0) return 0;

        long long initialPulse = 0;
        for (int idx = 0; idx < totalElements; ++idx) {
            if (idx % 2 == 0) {
                initialPulse += nums[idx];
            } else {
                initialPulse -= nums[idx];
            }
        }

        long long runningSum = nums[0];
        long long bestPosTerm = 2LL * nums[0];
        long long bestNegTerm = 0;
        long long bestGain = 0;

        for (int right = 1; right < totalElements; ++right) {
            long long signedVal = nums[right];
            if (right % 2 != 0) {
                signedVal = -nums[right];
            }

            runningSum += signedVal;

            long long currentGain = 0;
            if (right % 2 == 0) {
                currentGain = bestPosTerm - 2 * runningSum;
            } else {
                currentGain = bestNegTerm - 2 * runningSum;
            }

            bestGain = max(bestGain, currentGain);

            long long nextPos = (long long)nums[right] - signedVal + 2 * runningSum;
            long long nextNeg = (long long)-nums[right] - signedVal + 2 * runningSum;

            bestPosTerm = max(bestPosTerm, nextPos);
            bestNegTerm = max(bestNegTerm, nextNeg);
        }

        return initialPulse + bestGain;
    }
};