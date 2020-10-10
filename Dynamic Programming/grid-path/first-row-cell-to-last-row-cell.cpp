# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

// Given a grid of size N*M, find a path from any cell in the first row to any cell in last row
// you can go down-right or down or down-left only.

/*
TEST CASE:
3 4
5 1 2 6
9 9 7 5
3 1 4 8

======================
5 	1 	2 	6
10	10	8	7
13	9	11	15


*/

int main() {
	fastt;
	int r, c; cin >> r >> c;
	
	int arr[r][c];
	int dp[r][c];
	
	for (int i=0; i<r; i++) 
		for (int j=0; j<c; j++) {
			cin >> arr[i][j];
			dp[i][j] = INT_MAX; 
		}
	
	for(int i=0; i<c; i++) 
		dp[0][i] = arr[0][i];
	
	for(int i=1; i<r; i++) {
		for(int j=0; j<c; j++) {
			int ul = (j>0)? dp[i-1][j-1]: INT_MAX;
			int u = dp[i-1][j];
			int ur = (j<c-1)? dp[i-1][j+1]:INT_MAX; 
			
			dp[i][j] = arr[i][j] + min(ul, min(u, ur));
		}
	}
	
	int val=INT_MAX; 
	for(int i=0; i<c; i++) 
		if (dp[r-1][i] < val) 
			val=dp[r-1][i]; 
			
	cout << val << "\n"; 
	
	return 0;
}
