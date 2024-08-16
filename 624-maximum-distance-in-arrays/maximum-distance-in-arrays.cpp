class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = arrays[0].front();
        int maxi = arrays[0].back();
        int ans = 0;
        for(int i=1; i<arrays.size(); i++) {
            int currMin = arrays[i].front();
            int currMax = arrays[i].back();
            ans = max({ans, abs(currMin - maxi), abs(currMax - mini)});

            maxi = max(maxi, currMax);
            mini = min(mini, currMin);
        }
        return ans;
    }
};