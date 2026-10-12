class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        res=defaultdict(list)

        for s in strs:
            sorted_s=tuple(sorted(s))   

            res[sorted_s].append(s)  

        return list(res.values())