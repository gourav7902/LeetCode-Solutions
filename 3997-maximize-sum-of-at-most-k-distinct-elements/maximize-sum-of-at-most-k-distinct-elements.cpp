class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
       sort(nums.begin(), nums.end(), greater<int>());
       vector<int>temp;
      unordered_set<int>st;
       for(int i=0;i<n;i++){
        if(k>0){
           if(st.find(nums[i])==st.end()){
            st.insert(nums[i]);
             temp.push_back(nums[i]);
                k--;
           }
        }
       }
        return temp;
    }
};