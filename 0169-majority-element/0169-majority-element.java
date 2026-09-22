class Solution {
    public int majorityElement(int[] nums) {
        int cn = 0;
        int el = 0;
        for(int i = 0; i < nums.length; i++){
            if(cn == 0){
                el = nums[i];
            }
            if(nums[i] == el)
                cn++;
            else
                cn--;
        }
        return el;
    }
}