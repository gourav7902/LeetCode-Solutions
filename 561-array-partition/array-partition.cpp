class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n=nums.size();
         sort(nums.begin(), nums.end());
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i+=2){
            vp.push_back({nums[i],nums[i+1]});
        }
        int mini=0;
        int sum=0;
        for(auto x:vp){
            mini=min(x.first,x.second);
                sum+=mini;
        }
        return sum;
    }
};