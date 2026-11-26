
class Solution {
public:
    bool canAliceWin(int n) {
        int alice = 10;
        int bob = 9;
        int a = 0;
        int b = 0;

        while (n >= alice) {
            a++;
            n = n - alice;
            alice -= 2;

            if (n >= bob) {
                n = n - bob;
                b++;
                bob -= 2;
            }
        }

        if (a <= b) {
            return false;
        }

        return true;
    }
};
