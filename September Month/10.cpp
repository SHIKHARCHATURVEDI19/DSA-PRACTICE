class Solution {
public:
    long long solve(int x) {
        string s = to_string(x);
        int n = s.size();
        long long p = stoll(s.substr(0, (n + 1) / 2));

        long long ans = 1e18;

        for (long long q = p - 2; q <= p + 2; q++) {
            if (q <= 0) continue;

            string a = to_string(q);
            string b = a;

            for (int i = n / 2 - 1; i >= 0; i--)
                b += a[i];

            long long pal = stoll(b);

            if (pal > 0 && (pal % 2 == x % 2))
                ans = min(ans, abs((long long)x - pal) / 2);
        }

        return ans;
    }

    long long minimumOperations(vector<int>& nums) {
        vector<int> v = nums;

        long long ans = 0;
        for (int x : v)
            ans += solve(x);

        return ans;
    }
};

class Solution {
public:
    long long countShadowPairs(vector<int>& nums) {
        vector<int> n= nums;

        vector<int> st;
        long long ans = 0;

        for (int x : n) {
        
            while (!st.empty() && st.back() > x)
                st.pop_back();

            
            ans += lower_bound(st.begin(), st.end(), x) - st.begin();

            st.push_back(x);
        }

        return ans;
    }
};