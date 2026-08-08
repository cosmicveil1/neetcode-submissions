class Solution {
public:
    void findallcombination(int index,int target,vector<int> &arr,vector<vector<int>> &ans,vector<int> &ds){
     if(index==arr.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return;
     }

     //pick
     if(arr[index]<=target){
      ds.push_back(arr[index]);
      findallcombination(index,target-arr[index],arr,ans,ds);
      ds.pop_back();
     }
     //not pick
     findallcombination(index+1,target,arr,ans,ds);

    }
   
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findallcombination(0,target,nums,ans,ds);
        return ans;


    }
};
