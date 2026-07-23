#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        int l = 0;

        for (int r = 0; r < nums.size(); r++) {
            long long pro = 1;
            int i = l;

            cout << "\n===== r = " << r << " =====\n";
            cout << "l = " << l << ", i = " << i << endl;

            while (i <= r) {
                pro *= nums[i];   // Tumhari original line
                cout << "i = " << i
                     << ", nums[l] = " << nums[i]
                     << ", pro = " << pro << endl;
                i++;
            }

            cout << "Final Product = " << pro << endl;

            if (pro < k) {
                count++;
                cout << "Product < k, count = " << count << endl;
            } else {
                l++;
                cout << "Product >= k, l becomes " << l << endl;
            }
        }

        cout << "\nFinal Count = " << count << endl;
        return count;
    }
};

int main() {
    Solution s;

    vector<int> nums = {10, 5, 2, 6};
    int k = 100;

    cout << "Answer = " << s.numSubarrayProductLessThanK(nums, k) << endl;
}