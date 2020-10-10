# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second


// DP convert the O(2^n) to O(n^2)

bool knapsack(int s[], int sum, int n){
	bool dp[n+1][sum+1];
	
	for (int i=0; i<=n; i++)
		for (int j=0; j<=sum; j++)
			dp[i][j]=false;
			
	// base condition
        for (int i = 0; i <= n; i++) 
		dp[i][0] = true;
		
	for (int i = 1; i <= sum; i++) 
		dp[0][i] = false;
	
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=sum; j++) {
			// edge condition
			if(j < s[i-1]) 
				dp[i][j] = dp[i-1][j];
			
			// main condition
			if (j >= s[i-1]) dp[i][j] = (dp[i-1][j] || dp[i-1][j-s[i-1]]);
		}
	}
	
	for (int i=0; i<=n; i++) cout << s[i] << " ";
	cout << "\n";
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=sum; j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}
	
	return dp[n][sum];
}

int main(){
	fastt;
	
	int sum;
	int s[] = {3, 34, 4, 12, 5, 2};
	cin >> sum;

	int n = sizeof(s)/sizeof(s[0]);

	int val = knapsack(s, sum, n-1);
	if (val!=0) 
		cout << ("Found a subset with given sum") << val; 
	else
		cout << ("No subset with given sum "); 
	cout << endl;
	
	return 0;
}

