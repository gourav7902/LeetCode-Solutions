class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }
        int left=0;
        for(int i=0;i<n-1;i++){
            left+=nums[i];
            int right=totalsum-left;
            if((left-right)%2==0){
                count++;
            }
        }
        return count;
    }
};