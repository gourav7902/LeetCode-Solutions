class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n=seats.size();
        int m=students.size();
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int i=0;
        int j=0;
        int sum=0;
        while(i<n && j<m){
            sum=sum+abs(seats[i]-students[j]);
            i++;
            j++;
        }
        return sum;
    }
};