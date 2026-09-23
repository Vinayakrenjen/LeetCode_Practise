class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length == 0)return 0;
        HashSet<Integer>st = new HashSet<>();
        int longest = 1;
        for(int num : nums)
            st.add(num);
        for(int it : st){
            if(!st.contains(it-1)){
                int x = it;
                int count = 1;
                while(st.contains(x+1)){
                    count++;
                    x++;
                }
                longest = Math.max(longest,count);
            }    
        }
        return longest;
    }
}