class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        l=1
        r=1
        n=len(nums)

        while l<n and r<n:
            if nums[r]==nums[r-1]:
                r+=1
            else:
                nums[l]=nums[r]
                l+=1
                r+=1

        return l
        
    
        