class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int num=nums[i];
            if(count(nums.begin(),nums.end(),num)>n/2)
            return num;
        }
        return 0;
    }
};