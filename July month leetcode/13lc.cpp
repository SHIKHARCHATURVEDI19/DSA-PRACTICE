/*1291. Sequential Digits
Solved
Medium
Topics
premium lock icon
Companies
Hint
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
 

Constraints:

10 <= low <= high <= 10^9*/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int s=1;s<=9;s++){
            int num = 0;
            for(int d = s ;d<=9;d++){
                num = num *10 +d;
                if(num>= low && num<= high){
                    ans.push_back(num);
                }
            }
            
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};