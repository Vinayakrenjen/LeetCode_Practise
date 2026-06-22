class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum1 = nums[0];
        int sum2 = nums[0];
        int ans = nums[0];
        int maxsum = nums[0];
        int minsum = nums[0];
        for(int i = 1;i<nums.size();i++){
            sum1 = max(nums[i],sum1+nums[i]);
            maxsum = max(sum1,maxsum);
            sum2 = min(nums[i],sum2+nums[i]);
            minsum = min(sum2,minsum);
            ans = max(maxsum,abs(minsum));
        }
        return abs(ans);
        
    }
};