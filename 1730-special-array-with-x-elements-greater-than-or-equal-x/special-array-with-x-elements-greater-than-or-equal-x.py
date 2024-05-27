class Solution:
    def specialArray(self, nums: List[int]) -> int:
        maxi = max(nums)
        for i in range(maxi+1):
            temp = 0
            for j in nums:
                if(j>=i):
                    temp+=1
            if(temp==i): 
                return i
        return -1