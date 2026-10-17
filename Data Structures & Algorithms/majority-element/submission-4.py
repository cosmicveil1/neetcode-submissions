class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n=len(nums)
        for i in range(len(nums)):
            if (nums.count(nums[i]))>n/2:
                return nums[i]
        