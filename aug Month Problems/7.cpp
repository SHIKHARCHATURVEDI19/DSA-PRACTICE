3348. Smallest Divisible Digit Product II
Hard
Topics
premium lock icon
Companies
Hint
You are given a string num which represents a positive integer, and an integer t.

A number is called zero-free if none of its digits are 0.

Return a string representing the smallest zero-free number greater than or equal to num such that the product of its digits is divisible by t. If no such number exists, return "-1".

 

Example 1:

Input: num = "1234", t = 256

Output: "1488"

Explanation:

The smallest zero-free number that is greater than 1234 and has the product of its digits divisible by 256 is 1488, with the product of its digits equal to 256.

Example 2:

Input: num = "12355", t = 50

Output: "12355"

Explanation:

12355 is already zero-free and has the product of its digits divisible by 50, with the product of its digits equal to 150.

Example 3:

Input: num = "11111", t = 26

Output: "-1"

Explanation:

No number greater than 11111 has the product of its digits divisible by 26.

 

Constraints:

2 <= num.length <= 2 * 105
num consists only of digits in the range ['0', '9'].
num does not contain leading zeros.
1 <= t <= 1014


#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
    struct Factor {
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
    };

    Factor getFactors(long long t) {
        Factor f;
        while (t % 2 == 0) { f.c2++; t /= 2; }
        while (t % 3 == 0) { f.c3++; t /= 3; }
        while (t % 5 == 0) { f.c5++; t /= 5; }
        while (t % 7 == 0) { f.c7++; t /= 7; }
        if (t > 1) return {-1, -1, -1, -1}; // Invalid factor present
        return f;
    }

    Factor getDigitFactors(int d) {
        Factor f;
        while (d > 0 && d % 2 == 0) { f.c2++; d /= 2; }
        while (d > 0 && d % 3 == 0) { f.c3++; d /= 3; }
        while (d > 0 && d % 5 == 0) { f.c5++; d /= 5; }
        while (d > 0 && d % 7 == 0) { f.c7++; d /= 7; }
        return f;
    }

    // Minimum digits needed to satisfy the remaining required factor counts
    int minDigitsNeeded(Factor f) {
        int c2 = max(0, f.c2);
        int c3 = max(0, f.c3);
        int c5 = max(0, f.c5);
        int c7 = max(0, f.c7);

        int count = c5 + c7;
        count += (c3 + 1) / 2; // Each '9' satisfies two 3s
        int rem3 = c3 % 2;

        // Try to combine remaining 3 with a 2 to form 6, or use 8/4/2 for twos
        int c8 = c2 / 3;
        int rem2 = c2 % 3;

        if (rem3 == 1) {
            if (rem2 == 1) {
                // 3 * 2 = 6
                count += c8 + 1;
            } else if (rem2 == 2) {
                // 3 * 2 = 6, and remaining 2
                count += c8 + 2;
            } else { // rem2 == 0
                count += c8 + 1; // 3 -> '3'
            }
        } else {
            count += c8 + (rem2 > 0 ? 1 : 0);
        }

        return count;
    }

    // Greedily fill the tail with minimum possible number using given factors
    string getMinSuffix(Factor f, int len) {
        int c2 = max(0, f.c2);
        int c3 = max(0, f.c3);
        int c5 = max(0, f.c5);
        int c7 = max(0, f.c7);

        string res = "";
        for (int i = 0; i < c5; ++i) res += '5';
        for (int i = 0; i < c7; ++i) res += '7';

        int c9 = c3 / 2;
        int rem3 = c3 % 2;

        int c8 = c2 / 3;
        int rem2 = c2 % 3;

        int c6 = 0, c4 = 0, c3_digit = 0, c2_digit = 0;

        if (rem3 == 1) {
            if (rem2 == 1) {
                c6 = 1; rem2 = 0;
            } else if (rem2 == 2) {
                c6 = 1; rem2 = 1; // 6 and 2
            } else {
                c3_digit = 1;
            }
        }

        if (rem2 == 2) c4 = 1;
        else if (rem2 == 1) c2_digit = 1;

        for (int i = 0; i < c8; ++i) res += '8';
        for (int i = 0; i < c9; ++i) res += '9';
        for (int i = 0; i < c6; ++i) res += '6';
        for (int i = 0; i < c4; ++i) res += '4';
        for (int i = 0; i < c3_digit; ++i) res += '3';
        for (int i = 0; i < c2_digit; ++i) res += '2';

        while ((int)res.size() < len) {
            res += '1';
        }

        sort(res.begin(), res.end());
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        Factor req = getFactors(t);
        if (req.c2 == -1) return "-1";

        int n = num.length();

        // 1. First check if num contains '0', find first '0' index
        int first_zero = -1;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                first_zero = i;
                break;
            }
        }

        // If there's a 0, we can't keep any prefix including or past the '0'
        int max_prefix = (first_zero == -1) ? n : first_zero;

        // Vector to store prefix factor accumulations
        vector<Factor> pref(n + 1);
        for (int i = 0; i < max_prefix; ++i) {
            Factor df = getDigitFactors(num[i] - '0');
            pref[i + 1].c2 = pref[i].c2 + df.c2;
            pref[i + 1].c3 = pref[i].c3 + df.c3;
            pref[i + 1].c5 = pref[i].c5 + df.c5;
            pref[i + 1].c7 = pref[i].c7 + df.c7;
        }

        // Try to keep prefix of length i (from n down to 0)
        for (int i = max_prefix; i >= 0; --i) {
            int start_d = (i == n) ? (num[i - 1] - '0') : (i < n ? (num[i] - '0') + 1 : 1);
            if (i == n) {
                // Check if exact num works
                Factor rem = {req.c2 - pref[n].c2, req.c3 - pref[n].c3, req.c5 - pref[n].c5, req.c7 - pref[n].c7};
                if (minDigitsNeeded(rem) <= 0) {
                    return num;
                }
                continue;
            }

            for (int d = start_d; d <= 9; ++d) {
                Factor df = getDigitFactors(d);
                Factor rem = {
                    req.c2 - pref[i].c2 - df.c2,
                    req.c3 - pref[i].c3 - df.c3,
                    req.c5 - pref[i].c5 - df.c5,
                    req.c7 - pref[i].c7 - df.c7
                };

                int rem_len = n - 1 - i;
                if (minDigitsNeeded(rem) <= rem_len) {
                    string ans = num.substr(0, i);
                    ans += to_string(d);
                    ans += getMinSuffix(rem, rem_len);
                    return ans;
                }
            }
        }

        // If length n is not enough, construct the smallest number of length >= n + 1
        int req_len = max(n + 1, minDigitsNeeded(req));
        return getMinSuffix(req, req_len);
    }
};