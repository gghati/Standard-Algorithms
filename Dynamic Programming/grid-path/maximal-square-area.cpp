#include <bits/stdc++.h>
using namespace std;

/*
Question:-Given an m x n binary matrix filled with 0's and 1's,
find the largest square containing only 1's and return its area.

EX:-
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
*/

int maximalSquare(vector<vector<char>> &matrix)
{

    int n, m;
    n = matrix.size();
    m = matrix[0].size();
    int i, j;

    int dp[n][m];
    int ans = 0;

    for (i = 0; i < n; i++)
    {
        if (matrix[i][0] == '0')
        {
            dp[i][0] = 0;
        }
        else
        {
            ans = 1;
            dp[i][0] = 1;
        }
    }

    for (i = 0; i < m; i++)
    {
        if (matrix[0][i] == '0')
        {
            dp[0][i] = 0;
        }
        else
        {
            ans = 1;
            dp[0][i] = 1;
        }
    }

    for (i = 1; i < n; i++)
    {
        for (j = 1; j < m; j++)
        {
            if (matrix[i][j] == '0')
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = 1;
            }

            if (matrix[i - 1][j] == '1' && matrix[i][j - 1] == '1' && matrix[i - 1][j - 1] == '1')
            {
                dp[i][j] += min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
            ans = max(ans, dp[i][j]);
        }
    }

    return (ans * ans);
}

int main()
{
    int n, m;
    cout << "Enter no of rows: ";
    cin >> n;
    cout << "Enter no of columns: ";
    cin >> m;
    int i, j;
    vector<vector<char>> v(n, vector<char>(m, 0));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    cout << "Maximum area =" << maximalSquare(v);
}