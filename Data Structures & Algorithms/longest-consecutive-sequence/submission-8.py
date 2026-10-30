class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

       numbers=set(nums)

       best=0

       for num in numbers:
        if (num-1) not in numbers:
            current_num=num
            current_length=1

            while (current_num+1) in numbers:
                current_num+=1
                current_length+=1

            best=max(best,current_length)

       return best

        


            

        