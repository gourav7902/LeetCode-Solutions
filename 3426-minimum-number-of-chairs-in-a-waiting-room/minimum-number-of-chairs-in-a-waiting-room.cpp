class Solution {
public:
    int minimumChairs(string s) {
        int p=0;
        int ac=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='E'){
                p++;
            }
            else
            {
                p--;
            }
            ac=max(ac,p);
           
        }
        return ac;
    }
};