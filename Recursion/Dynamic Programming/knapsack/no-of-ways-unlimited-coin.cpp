# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

const int M = 1e9+7;
 
int main() {
	fastt;
	
	int n, sum; 	
	cin >> n >> sum;
	int arr[n];
	
	for (int i=0; i<n; i++) cin >> arr[i];
	
	int dp[n+1][sum+1];
	
	// base condition
	for (int i=0; i<=n; i++)
		dp[i][0]=1;
	for (int i=1; i<=sum; i++)
		dp[0][i]=0;
	
	for (int i=1; i<=n; i++)
		for (int j=1; j<=sum; j++)
			dp[i][j]=0;
	
	// Method 1, where state is sum and n
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=sum; j++) {
			// edge condition
			if (j < arr[i-1]) 
				dp[i][j] = dp[i-1][j];
				
			else // main condition
			dp[i][j] = (dp[i][j-arr[i-1]] + dp[i-1][j])%M;
		}
	}
	
	// print the after process matrix 
	cout << "=====================\n";
	for (int i=0; i<=n; i++){
		for (int j=0; j<=sum; j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}
	
	cout << dp[n][sum] << "\n"; 
	
	return 0;
}

