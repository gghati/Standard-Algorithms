# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

int knapsack(int v[], int w[], int W, int n){
	int dp[n+1][W+1];
	
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=W; j++) {
			//base Condition 
			//intialization
			if (i==0 || j==0)
				dp[i][j] = 0;
			
			else {
				if (w[i-1] <= W)
					dp[i][j] = max(v[i-1] + dp[i-1][j-w[i-1]], dp[i-1][j]);
				else dp[i][j] = dp[i-1][j]; 
			}
		}
	}
	
	return dp[n][W];
}

int main(){
	fastt;
	
	int val[] = {60, 100, 120};
	int wt[] = {10, 20, 30};
	int W = 50;
	
	int n = sizeof(wt)/sizeof(wt[0]);
	
	cout << knapsack(val, wt, W, n) << endl;
	
	return 0;
}

