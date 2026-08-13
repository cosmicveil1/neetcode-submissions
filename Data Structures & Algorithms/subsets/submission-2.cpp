class Solution {

    void subsetans(int i,vector<vector<int>>& ans,vector<int> &ds,vector<int> &nums){

        //pick/ not pick
        if(i==nums.size()){
            ans.push_back(ds);
            return;
        }

        //add the element in the ds in case of picking the element
        ds.push_back(nums[i]);
        subsetans(i+1,ans,ds,nums);
        //remove the element when the recursion ends during backtracking
        ds.pop_back();

        
        //simply go to the next index
        subsetans(i+1,ans,ds,nums);

    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        subsetans(0,ans,ds,nums);
        return ans;

    }
};
