class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN;
        int size = 1;
        int sum = 0;
        int reducer = 0;
        for(int i=0;i<nums.size();i++) {
            if(size < k) {
                sum+=nums[i];
                size++;
                continue;
            }
            sum+=nums[i];
            double temp = (double) sum / k;
            ans = max(ans, temp);
            sum-=nums[reducer++];
        }
        return ans;
    }
};