class Solution {
    public int minMoves(int[] nums) {
        int m=0;
        int mini=Integer.MAX_VALUE;
        for(int i=0;i<nums.length;i++){
            mini=Math.min(mini,nums[i]);
        }
        for(int j=0;j<nums.length;j++){
            m=m+nums[j]-mini;
        }
        return m;
    }
}