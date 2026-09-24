class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> ans = new ArrayList<>();
        ans.add(1);
        long res = 1;
        for(int c = 1; c < rowIndex+1; c++){
            res = res * (rowIndex + 1 - c);
            res = res / c;
            ans.add((int)res);
        }
        return ans;
    }
}