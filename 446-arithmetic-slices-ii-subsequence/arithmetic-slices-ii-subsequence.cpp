class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res=0;
        int n = nums.size();
        unordered_map<long,int> m[n];
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                long diff = (long) nums[i]-nums[j];
                auto it = m[j].find(diff);
                int c = it == end(m[j]) ? 0 : it->second;
                m[i][diff] += c+1;
                res+=c;
            }
        }
        return res;
    }
};