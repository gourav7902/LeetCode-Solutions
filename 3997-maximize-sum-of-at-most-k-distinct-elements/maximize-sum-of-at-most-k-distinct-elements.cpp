class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
       sort(nums.begin(), nums.end(), greater<int>());
       int maxsum=0;
       vector<int>temp;
       int count=0;
       for(int i=0;i<n;i++){
        if(k>0){
            if(i==0||nums[i]!=nums[i-1]){
                temp.push_back(nums[i]);
                 k--;
            }
        }
       }
        return temp;
    }
};