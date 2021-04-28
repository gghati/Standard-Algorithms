class Solution {
public:
    string generateTheString(int n) {
        string s;
        if(n%2==0) {
            n--;
            while(n--)s=s+'a';
            s=s+'b';
            return s;
        }
        while(n--)s=s+'a';        
        return s;
    }
};
