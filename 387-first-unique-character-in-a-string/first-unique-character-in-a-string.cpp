class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.length();
      map<char,int>mp;
      for(int i=0;i<s.length();i++){
            char ch=s[i];
            mp[ch]++;
      }
      for(int i=0;i<n;i++){
        if(mp[s[i]]==1){
            return i;
        }
    }
    return -1;
    }
};