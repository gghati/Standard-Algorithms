class Solution {
public:
    void dfs(vector<vector<char>> &grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!='1')return;
        
        grid[i][j]='0';
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
    }
    int numIslands(vector<vector<char>> grid) {
        int ans=0;
        for(int i=0; i<grid.size(); i++)
            for(int j=0; j<grid[0].size(); j++)
                if(grid[i][j]=='1') dfs(grid, i, j), ++ans;
        return ans;
    }
};
