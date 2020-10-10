# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

// DP convert the O(2^n) to O(n^2)

int fabonic(int n){
	int dp[n+1];
	
	// base condition 
	dp[0]=0;
	dp[1]=1;

	for(int i=2; i<=n; i++)
		dp[i]=dp[i-1] + dp[i-2];
	
	return dp[n];
}

int main(){
	fastt;
	
	int val;
	cin >> val;
	
	cout << fabonic(val) << endl;
}

