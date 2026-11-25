class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int sum=0;
        int temp=nums[n-1];
        while(k>0){
            sum+=temp;
            temp++;
            k--;
        }
        return sum;
    }
};