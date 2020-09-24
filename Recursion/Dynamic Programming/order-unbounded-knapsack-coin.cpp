# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second
# define MAX 1002
 
ll M = 1e9+7; 
 
 
ll knapsack(int arr[], ll sum){
	
	ll dp[sum+1] = {0};
	
	// base condi
	dp[0]=1;
	
	for (int i=1; i<=sum; i++)
		for(int j=1; j<=min(6, i); j++)
			dp[i] = (dp[i]+dp[i-j])%M;
	
	return dp[sum];
	
	
	/*
	
	// base condition
	if (sum==0) return 1;
	if (sum<0) return 0; 
	
	// logic 
	int val=0;
	for (int i=1; i<=min(6, sum); i++)
		val += knapsack(arr, sum-i) ;
	return val;  
	
	*/
}
 
int main() {
	fastt;
	
	ll sum; cin >> sum;
	int arr[] = {1, 2, 3, 4, 5, 6};
	
	cout << knapsack(arr, sum) << "\n";
		
	return 0;
}

