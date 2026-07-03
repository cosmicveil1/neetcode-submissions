class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int streak=0;
        int current=0;
        int longest=1;
        unordered_set<int> elements;

        for(int i=0;i<nums.size();i++){
           elements.insert(nums[i]);
        }

        for(int num:elements){
            if(!elements.count(num-1)){
               current=num;
               streak=1;

            while(elements.count(current+1)){
                current++;
                streak++;
            }
            }
            longest=max(longest,streak);
        }

 return longest;
    }
};
