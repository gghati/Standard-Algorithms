# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second


// min number of the Coins required for the value
// Both Recursion and Dp version

int knapsack(int arr[], int sum, int n){
	
	int dp[sum+1];
	dp[0] = 0;
	
	for(int i=1; i<=sum; i++)
		dp[i]=INT_MAX; 
	
	for (int i=0; i<=sum; i++) {
		for (int j=0; j<n; j++){
			if (arr[j] <= i) {
				int sub = dp[i-arr[j]];
				if (sub+1<dp[i] && sub!=INT_MAX) dp[i]=sub+1;
			}
		}
	}
	
	return dp[sum];
	
	/*
	
	// base case
	if (sum==0) return 0; 
	
	int val=INT_MAX; 
	for(int i=0; i<n; i++) {
		if (arr[i] <= sum) {
			int temp = knapsack(arr, sum-arr[i], n);
			if (temp+1<val && temp!=INT_MAX) val=temp+1; 
		}
	}

	return val; 

	*/
}

int main() {
	fastt;
	
	int n, sum;
	cin >> n >> sum;
	
	int arr[n];
	
	for (int i=0; i<n; i++) cin >> arr[i];
	
	int val=knapsack(arr, sum, n);
	
	cout << ((val==INT_MAX)? -1:val) << "\n";
		
	return 0;
}
