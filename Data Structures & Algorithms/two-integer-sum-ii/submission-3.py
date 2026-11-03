class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        # applying 2 pointer approach
        n=len(nums)
        i=0
        j=n-1

        while i<n and j>=0:
            if nums[i]+nums[j]>target:
                j-=1
            elif nums[i]+nums[j]<target:
                i+=1
            else:
               return [i+1,j+1]

        return []









        