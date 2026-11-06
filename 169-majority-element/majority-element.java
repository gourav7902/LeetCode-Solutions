class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer,Integer> m = new HashMap<>();
        for(int n:nums){
            m.put(n,m.getOrDefault(n,0)+1);
        }
        for(int key:m.keySet()){
            if(m.get(key)>nums.length/2)
                return key;
        }
        return -1;
    }
}