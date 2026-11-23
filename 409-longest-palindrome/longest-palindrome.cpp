class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length();
        map<char,int>freq;
        int maxi=0;
        for(int i=0;i<n;i++){
            freq[s[i]]++;
        }
        bool oddfreq=false;
        for(auto it:freq){
            if(it.second%2==0){
                maxi+=it.second;
            }
            else
            {
                maxi+=it.second-1;
                oddfreq=true;
            }
        }
        if(oddfreq){
            maxi++;
        }
        return maxi;
    }
};