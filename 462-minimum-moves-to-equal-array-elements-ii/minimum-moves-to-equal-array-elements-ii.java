class Solution {
    public int minMoves2(int[] nums) {
           Arrays.sort(nums);
            int s=0;
            int e=nums.length-1;
            int mid=s+(e-s)/2;
            int median=nums[mid];
        int moves = 0;
        for (int i = 0; i < nums.length; i++) {
            moves=moves+Math.abs(nums[i] - median);
        }

        return moves;
    }
}