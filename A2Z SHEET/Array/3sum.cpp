/*15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105*/

#include <iostream>   // Input/Output ke liye
#include <vector>     // Vectors use karne ke liye
#include <algorithm>  // Sort function ke liye

using namespace std;  // Taaki baar-baar std:: na likhna pade

/*Solution*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        // 1. Array ko sort karein taaki hum duplicate skip kar sakein
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            // 2. Agar current number pichle jaisa hi hai, toh skip karein (No Duplicates)
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int low = i + 1;
            int high = n - 1;

            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];

                if (sum == 0) {
                    // 3. Perfect match mil gaya! Ans mein add karein ye list hai banaya 
                    //list aise banaya karte hain == vector<int> row={nums[i], nums[low], nums[high]};
                    ans.push_back({nums[i], nums[low], nums[high]});

                    // 4. Agle numbers agar same hain toh unhe skip karein
                    while (low < high && nums[low] == nums[low + 1]) low++;
                    while (low < high && nums[high] == nums[high - 1]) high--;

                    // 5. Pointers ko aage badhayein
                    low++;
                    high--;
                } 
                else if (sum < 0) {
                    // 6. Sum chota hai, humein bada number chahiye (Move Right)
                    low++;
                } 
                else {
                    // 7. Sum bada hai, humein chota number chahiye (Move Left)
                    high--;
                }
            }
        }
        return ans;
    }
};

/*SUMMARY - pahle sort kardo duplicate skip karne ke liye 3 POINTER BANAO pahla 0 par dusre i+1 or last nums size-1 do loop lagao pahla 
 itrate kare i ko dusrea while ko do condition bhi agar same ho toh i++ or h-- kardo if else sum chhota ho 
 low++ nahi high -- */