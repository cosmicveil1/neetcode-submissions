class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        // 1. Sort the array to use the two-pointer technique
        sort(nums.begin(), nums.end());

        // 2. First fixed pointer (i)
        for (int i = 0; i < n; i++) {
            // Skip duplicate values for the 1st number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // 3. Second fixed pointer (j)
            for (int j = i + 1; j < n; j++) {
                // Skip duplicate values for the 2nd number
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // 4. Moving pointers (p and q)
                int p = j + 1;
                int q = n - 1;

                while (p < q) {
                    // Use long long to prevent integer overflow during addition
                    long long sum = (long long)nums[i] + nums[j] + nums[p] + nums[q];

                    if (sum < target) {
                        p++;
                    } else if (sum > target) {
                        q--;
                    } else {
                        // Found a valid quadruplet!
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++;
                        q--;

                        // Skip duplicate values for the 3rd moving pointer
                        while (p < q && nums[p] == nums[p - 1]) p++;
                        // Skip duplicate values for the 4th moving pointer
                        while (p < q && nums[q] == nums[q + 1]) q--;
                    }
                }
            }
        }
        
        return ans; 
    }
};