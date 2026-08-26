class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # n=len(nums)
        # ans=[0]*n


        # for i in range(n):
        #     for j in range(i+1,n):
        #         if nums[i]+nums[j]==target:
        #          return [i,j]
        
        # return []
        

        seen={}

        for i,num in enumerate(nums):
            diff=target-num

            if diff in seen:
                return [seen[diff],i]

            seen[num]=i

        return []






