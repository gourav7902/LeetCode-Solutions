
class Solution {
public:
    bool canAliceWin(int n) {
        int alice = 10;
        int bob = 9;
        int a=0;
        int b=0;
        while (n >= alice) {
            a++;
            n = n - alice;//17
            alice-=2;
            if (n >= bob) {
                b++;
                n = n - bob;//8
                bob-=2;
            }
        }
       if(a<=b){
        return false;
       }
       return true;
    }
};
