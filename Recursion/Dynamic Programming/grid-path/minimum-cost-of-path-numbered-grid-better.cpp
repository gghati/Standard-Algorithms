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
5 6 8 14 
14 15 15 19 
17 16 19 27

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
	
	dp[0][0] = arr[0][0];
	for(int i=1; i<r; i++)
		dp[i][0] = arr[i][0] + dp[i-1][0];
	
	for(int i=1; i<c; i++)
		dp[0][i] = arr[0][i] + dp[0][i-1];
	
	for (int i=1; i<r; i++)
		for (int j=1; j<c; j++)
			dp[i][j]=arr[i][j] + min(dp[i][j-1], dp[i-1][j]);
		
	cout << "==================\n";
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}
	
	return 0;
}
