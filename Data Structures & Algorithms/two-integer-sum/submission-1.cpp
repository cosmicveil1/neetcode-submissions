class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int,int> mp;
        
        int n=arr.size();
        for(int i=0;i<n;i++){
        int complement=target-arr[i];

        if(mp.count(complement))
        return {mp[complement],i};

        mp[arr[i]]=i;
        }
        return {};
    }
};
