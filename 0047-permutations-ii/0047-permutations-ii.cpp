class Solution {
public:
    void perm(vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, vector<bool>& used){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i = 0; i<nums.size(); i++){
            if(used[i])
                continue;
            if(i>0 && nums[i]==nums[i-1] && !used[i-1])
                continue;
            ds.push_back(nums[i]);
            used[i] = true;
            perm(nums,ds,ans,used);
            ds.pop_back();
            used[i] = false;
        }    
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ds;
        vector<vector<int>>ans;
        vector<bool>used(nums.size(),false);
        perm(nums,ds,ans,used);
        return ans;    
    }
};