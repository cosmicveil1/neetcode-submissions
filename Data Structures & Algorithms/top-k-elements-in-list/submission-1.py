class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        counts={}

        for num in nums:
            counts[num]=counts.get(num,0)+1

        sorted_nums=sorted(counts.keys(),key=lambda x:counts[x],reverse=True)

        return sorted_nums[:k]



        