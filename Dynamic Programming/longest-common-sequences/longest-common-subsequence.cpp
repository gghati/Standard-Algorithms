# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

int main() {
	fastt;
	
	string A, B;
	cin >> A >> B;
	
	int n = A.length();
	int m = B.length();
	int dp[n+1][m+1];

	for (int i=0; i<=n; i++) 
		for (int j=0; j<=m; j++)
			dp[i][j] = 0; 
		
	for (int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if (A[i-1]==B[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max( dp[i-1][j], dp[i][j-1] ); 
		}
	}
	
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=m; j++)
			cout << dp[i][j]; 
		cout << "\n";
	}
	
	cout << dp[n][m] << "\n"; 
	return 0;
}
