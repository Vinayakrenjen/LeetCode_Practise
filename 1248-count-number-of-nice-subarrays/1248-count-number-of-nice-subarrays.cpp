class Solution {
public:
    int count(vector<int>& nums, int k){
        int l = 0;
        int countodd = 0;
        int count = 0;
        for(int r = 0;r<nums.size();r++){
            if(nums[r]%2!=0)
                countodd++;
            while(countodd>k){
                if(nums[l]%2!=0)
                    countodd--;
                l++;
            }
            count+=r-l+1;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return count(nums,k)-count(nums,k-1);
    }
};