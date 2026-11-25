class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n=apple.size();
        int m=capacity.size();
        sort(capacity.begin(), capacity.end(),greater<int>());
        int sum=0;
        int box=0;
        for(int i=0;i<n;i++){
            sum+=apple[i];
        }
        for(int j=0;j<m;j++){
           sum-=capacity[j];
           box++;
           if(sum<=0){
            return box;
           }
        }
        return box;
    }
};