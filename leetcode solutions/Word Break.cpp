class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        bool dp[n+1];
        
        for(int i=0; i<=n; i++) 
            dp[i]=false;
        dp[0]=true;
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<i; j++){
                if(dp[j] && findstr(wordDict, string(s.begin()+j, s.begin()+i))) {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }

    bool findstr(vector<string>& wordDict, string word){
        for(string s: wordDict)
            if(s==word) return true;
        return false;
    }
};
