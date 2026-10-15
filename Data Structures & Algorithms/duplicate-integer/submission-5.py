class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        freq={}
        for num in nums:
            freq[num]=freq.get(num,0)+1
           


        for num,value in freq.items():
            if freq[num]!=1:
                return True
            
        return False

         

        