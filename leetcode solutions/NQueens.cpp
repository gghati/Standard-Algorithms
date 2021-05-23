class Solution {
public:
    bool check(vector<string> b, int i, int j){
        int n = b.size();

        int k=0;
        while(k<n){
            if(k!=j && b[i][k]=='Q'){ return false; }
            if(k!=i && b[k][j]=='Q'){ return false; }
            k++;
        }

        k=1; 
        while(i-k>=0 && j-k>=0) { 
            if(b[i-k][j-k]=='Q'){ return false; }
            k++;
        }

        k=1; 
        while(i-k>=0 && j+k<n) { 
            if(b[i-k][j+k]=='Q'){ return false; }
            k++;
        }

        return true; 
    }
    
    vector<vector<string>> ans; 
    
    void addqueen(vector<string> b, int n){
        if(n==0){
            ans.push_back(b);
            return; 
        }
        
        int i = b.size()-n; 
        for(int j=0; j<b[0].size(); j++) {
            vector<string> tb=b;
            if(tb[i][j]=='.' && check(tb, i, j)){
                tb[i][j]='Q';
                addqueen(tb, n-1);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> b;
        for(int i=0; i<n; i++){
            string s="";
            for(int j=0; j<n; j++)
                s.push_back('.');
            b.push_back(s);
        }
        addqueen(b, n);
        return ans;
    }
};
