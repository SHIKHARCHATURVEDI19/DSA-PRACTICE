class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n), last(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int,int>> intervals;

        // Only first occurrences can be starting points
        for (int i = 0; i < n; i++) {
            int ch = s[i] - 'a';

            if (first[ch] != i)
                continue;

            int L = i;
            int R = last[ch];
            bool valid = true;

            for (int j = L; j <= R; j++) {
                int c = s[j] - 'a';

                // This character occurs before L,
                // so [L, R] can never be valid.
                if (first[c] < L) {
                    valid = false;
                    break;
                }

                R = max(R, last[c]);
            }

            if (valid)
                intervals.push_back({L, R});
        }

        // Earliest finishing interval first
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int prevEnd = -1;

        for (auto &[L, R] : intervals) {
            if (L > prevEnd) {
                ans.push_back(s.substr(L, R - L + 1));
                prevEnd = R;
            }
        }

        return ans;
    }
};