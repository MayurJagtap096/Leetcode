class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int num=0;
        for(int i=0;i<nums.size();i++) {
            for(int j=i+1;j<nums.size();j++) {
                num = nums[i]+nums[j];
                int st = j+1;
                int end = nums.size()-1;
                while(st<=end) {
                    int mid = (st+end)/2;
                    if(nums[mid]<num) st=mid+1;
                    else end=mid-1;
                }
                ans+=end-j;
            }
        }
        return ans;
    }
};