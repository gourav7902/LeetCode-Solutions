class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int mini = 0;

        for(int i = 0; i < n; i += 2) {
            char ch1 = s[i];
            char ch2 = s[i+1];

            if(ch1 != ch2) {
                mini++;
            }
        }

        return mini;
    }
};