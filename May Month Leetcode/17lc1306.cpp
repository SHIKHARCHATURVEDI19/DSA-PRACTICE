
/*1306. Jump Game III

Medium

Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach any index with value 0.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 
Example 2:

Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true 
Explanation: 
One possible way to reach at index 3 with value 0 is: 
index 0 -> index 4 -> index 1 -> index 3
Example 3:

Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.
 

Constraints:

1 <= arr.length <= 5 * 104
0 <= arr[i] < arr.length
0 <= start < arr.length*/

/*SOLUTION*/

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // 1. Boundary check aur Visited check (agar element < 0 hai toh matlab visited hai)
        if (start < 0 || start >= arr.size() || arr[start] < 0) {
            return false;
        }
        
        // 2. Target mil gaya
        if (arr[start] == 0) {
            return true;
        }
        
        // 3. Current element ko visited mark karne ke liye negative bana do
        int jump = arr[start];
        arr[start] = -arr[start]; 
        
        // 4. Dono paths ko explore karo (Forward OR Backward)
        // Agar kisi bhi ek raste se 0 mil gaya, toh true return hoga
        return canReach(arr, start + jump) || canReach(arr, start - jump);
    }
};