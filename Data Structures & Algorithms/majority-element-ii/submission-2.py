class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        
        n=len(nums)
        count={}
        listt=[]

        for num in nums:
            count[num]=count.get(num,0)+1

        for num,freq in count.items():
            if freq>n/3:
                listt.append(num)

        return listt



        