class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        int ans = 0;

        while(i < j) {

            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                int k = j;

                while(s[k] != s[i]) {
                    k--;
                }

                if(k == i) {
                    // s[i] is the middle character
                    swap(s[i], s[i + 1]);
                    ans++;
                }
                else {
                    while(k < j) {
                        swap(s[k], s[k + 1]);
                        k++;
                        ans++;
                    }

                    i++;
                    j--;
                }
            }
        }

        return ans;
    }
};