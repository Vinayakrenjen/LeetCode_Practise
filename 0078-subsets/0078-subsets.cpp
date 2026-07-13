class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int i,vector<int>&nums,vector<int>&curr){
        if(i == nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        dfs(i+1,nums,curr);
        curr.pop_back();
        dfs(i+1,nums,curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        dfs(0,nums,curr);
        return ans;
    }
};