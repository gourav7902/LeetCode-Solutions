
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        int maxp = 0;

        sort(nums.begin(), nums.end());

        for(int i = n - 3; i >= 0; i--) {
            int sum = 0;

            if(nums[i] + nums[i + 1] > nums[i + 2]) {
                sum = nums[i] + nums[i + 1] + nums[i + 2];
                maxp = max(maxp, sum);
            }
        }

        return maxp;
    }
};
