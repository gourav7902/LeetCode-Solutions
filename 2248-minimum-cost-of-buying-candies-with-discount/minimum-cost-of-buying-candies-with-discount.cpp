class Solution {
public:
    int minimumCost(vector<int>& cost) {
        std::sort(cost.begin(), cost.end(), std::greater<int>());
         int n=cost.size();
        int res=0;
        for(int i=0;i<n;i++){
            if(i%3!=2){
                res+=cost[i];
            }
        }
        return res;
    }
};