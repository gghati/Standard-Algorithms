# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

// Given a grid of size N*M, find a path from cell (1, 1) to (N, M) which minimize the cost
// you can go right or down only.

/*
TEST CASE:

3 4
5 1 2 6
9 9 7 5 
3 1 4 8 


OUTPUT:

==================
27 22 21 19 
25 22 19 13 
16 13 12 8

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
	
	for (int i=r-1; i>=0; i--) {
		for (int j=c-1; j>=0; j--) {
			int right = (j<c-1)? dp[i][j+1]:INT_MAX;
			int down = (i<r-1)? dp[i+1][j]: INT_MAX;
			
			if (i==r-1 && j==c-1)
				dp[i][j] = arr[i][j];
			else
				dp[i][j] = arr[i][j] + min(right, min(down, dp[i][j]));
		}
	}
	
	cout << "==================\n";
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}
		
	return 0;
}
