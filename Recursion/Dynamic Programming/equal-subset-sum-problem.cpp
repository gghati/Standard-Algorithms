# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second


// DP convert the O(2^n) to O(n^2)
// Equal Sum partition problem


// function return true if sum is the sum of the array
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
		
	return dp[n][sum];
}

bool check(int s[], int n) {
	int sum=0; 
	for (int i=0; i<n; i++)
		sum += s[i]; 

	if (sum%2!=0) return false;
	
	return knapsack(s, sum/2, n);
}

int main(){
	fastt;
	
	int n; cin >> n;
	
	int s[n];
	
	for (int i=0; i<n; i++) cin >> s[i];
	
	if (check(s, n) == true) 
		cout << ("Found a Equal sum Partition"); 
	else
		cout << ("No subset with given Equal Partition!"); 
	cout << endl; 
	return 0;
}


