class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        int res=0;
        int ones=0;
        vector<int> vec(2*n);
        for(int i=0;i<n;i++) {
            if(nums[i]) ones++;
            vec[i] = nums[i];
        }
        for(int i=n;i<2*n;i++) {
            vec[i] = nums[i-n];
        }
        int i=0,j=0;
        while(i<2*n && j<2*n) {
            
            if(vec[j]) {
                ans++;
            }
            if((j-i+1)==ones) {
                res = max(ans,res);
                if(vec[i]==1) ans--;
                i++;
            }
            j++;
        }
        return ones-res;
    }
};
