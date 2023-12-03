class Solution {
public:
    int numTeams(vector<int>& r) {
        int n = r.size();
        int ans = 0;

        vector<int> dp1(n), dp2(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (r[i] < r[j]) {
                    dp1[i]++;
                } else if (r[i] > r[j]) {
                    dp2[i]++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (r[i] < r[j]) {
                    ans += dp1[j];
                } else if (r[i] > r[j]) {
                    ans += dp2[j];
                }
            }
        }

        return ans;
    }
};