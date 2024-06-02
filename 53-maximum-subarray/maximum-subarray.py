class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxi = -99999
        curr = 0
        for i in range(len(nums)):
            curr += nums[i]
            if curr > maxi:
                maxi = curr
            if curr<0:
                curr = 0
        return maxi
            