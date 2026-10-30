class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:

        res={}
        n=len(nums)
        result=[]
        
        for num in nums:
            res[num]=res.get(num,0)+1

        for num,freq in res.items():
            if freq>n/3:
                result.append(num)

        return result





        
        