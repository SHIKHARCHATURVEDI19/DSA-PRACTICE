/*1674. Minimum Moves to Make Array Complementary

You are given an integer array nums of even length n and an integer limit. In one move, you can replace any integer from nums with another integer between 1 and limit, inclusive.

The array nums is complementary if for all indices i (0-indexed), nums[i] + nums[n - 1 - i] equals the same number. For example, the array [1,2,3,4] is complementary because for all indices i, nums[i] + nums[n - 1 - i] = 5.

Return the minimum number of moves required to make nums complementary.

Example 1:

Input: nums = [1,2,4,3], limit = 4
Output: 1
Explanation: In 1 move, you can change nums to [1,2,2,3] (underlined elements are changed).
nums[0] + nums[3] = 1 + 3 = 4.
nums[1] + nums[2] = 2 + 2 = 4.
nums[2] + nums[1] = 2 + 2 = 4.
nums[3] + nums[0] = 3 + 1 = 4.
Therefore, nums[i] + nums[n-1-i] = 4 for every i, so nums is complementary.
Example 2:

Input: nums = [1,2,2,1], limit = 2
Output: 2
Explanation: In 2 moves, you can change nums to [2,2,2,2]. You cannot change any number to 3 since 3 > limit.
Example 3:

Input: nums = [1,2,1,2], limit = 2
Output: 0
Explanation: nums is already complementary.
 

Constraints:

n == nums.length
2 <= n <= 105
1 <= nums[i] <= limit <= 105
n is even.*/
/*Solution*/
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        // diff array hamara 'cost counter' hai
        vector<int> diff(2 * limit + 2, 0);
        int n = nums.size();

        for (int i = 0; i < n / 2; ++i) {
            int a = nums[i];
            int b = nums[n - 1 - i];

            // Maan lo har pair ko badalne mein 2 moves lagenge (Sabse mehnga sauda)
            // Ab check karte hain ki kahan kahan 'discount' mil sakta hai.

            // 1 Move wala discount kab milega?
            // Jab target sum itna ho ki sirf ek number badal ke kaam chal jaye.
            int left = min(a, b) + 1;       // Sabse chota sum jo 1 move mein ban sake
            int right = max(a, b) + limit;  // Sabse bada sum jo 1 move mein ban sake

            // Is range mein humne 1 move ka discount de diya
            diff[left] -= 1;
            diff[right + 1] += 1;

            // 0 Move wala 'Bumper Discount'!
            // Agar target sum pehle se hi (a + b) ke barabar hai, toh koi mehnat nahi karni.
            // Ek discount pehle hi mil chuka tha range wale step mein, 
            // ek aur minus kar do taaki total 0 moves ho jayein.
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
        }

        // Shuruat mein total cost n moves (yani har pair ke 2 moves)
        int min_moves = n;
        int current_moves = n;

        // Ab har sum pe jaake check karo ki kahan sabse sasta pad raha hai
        for (int s = 2; s <= 2 * limit; ++s) {
            current_moves += diff[s]; // Discounts apply karte chalo
            min_moves = min(min_moves, current_moves);
        }

        return min_moves;
    }
};