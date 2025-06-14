class Solution {
public:
    int n;
    bool isValid(vector<int>& nums, int mid, int pairs) {
        int countOfPairs = 0;
        int i=0;
        while(i<n-1) {
            if(nums[i+1] - nums[i] <= mid) {
                countOfPairs++;
                i+=2;
            }
            else {
                i++;
            }
        }
        return countOfPairs >= pairs;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        int ans = INT_MAX;
        int l = 0;
        int r = nums[n-1] - nums[0];

        while(l<=r) {
            int mid = l + (r - l)/2;
            if(isValid(nums, mid, p)) {
                ans = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return ans;
    }
};