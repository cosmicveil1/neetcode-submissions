class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        if len(nums)<=1:
            return nums

        left_arr=nums[:len(nums)//2]
        right_arr=nums[len(nums)//2:]

        self.sortArray(left_arr)
        self.sortArray(right_arr)

        # merge\
        i=0
        j=0
        k=0  #merged array index
        while i<len(left_arr) and j<len(right_arr):
            if left_arr[i]<right_arr[j]:
                nums[k]=left_arr[i]
                i+=1
                k+=1
            else:
                nums[k]=right_arr[j]
                j+=1
                k+=1

        while i<len(left_arr):
            nums[k]=left_arr[i]
            i+=1
            k+=1

        while j<len(right_arr):
            nums[k]=right_arr[j]
            j+=1
            k+=1

        return nums

        


        
        