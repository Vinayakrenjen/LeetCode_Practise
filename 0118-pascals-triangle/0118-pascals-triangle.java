class Solution {
    public List<Integer> rows(int i){
        List<Integer> ans = new ArrayList<>();
        ans.add(1);
        int res = 1;
        for(int col = 1; col < i; col++){
            res = res*(i-col);
            res = res/col;
            ans.add(res);
        }
        return ans;
    }
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<>();
        for(int i = 1; i <= numRows; i++){
            res.add(rows(i));
        }
        return res;
    }
}