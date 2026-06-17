class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;

        int write=0;
        for(int scan=1;scan<nums.size();scan++){
            if(nums[scan]!=nums[write])
            write++;
            nums[write]=nums[scan];
        }
        return write+1;
    }
};