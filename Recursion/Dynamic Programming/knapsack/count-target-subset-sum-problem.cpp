# include <iostream> 
using namespace std;


int knapsack(int arr[], int n, int sum){
	int dp[n+1][sum+1]; 
	
	for (int i=0; i<=n; i++)
		dp[i][0] = 1; 
		
	for (int j=1; j<=sum; j++)
		dp[0][j] = 0;
	
	for(int i=1; i<=n; i++) {
		for (int j=1; j<=sum; j++) {
			// edge case
			if (j < arr[i-1])
				dp[i][j] = dp[i-1][j];
				
			else dp[i][j] = ( dp[i-1][j] + dp[i-1][j-arr[i-1]] );
		}
	}
	
	for (int i=0; i<n; i++) cout << arr[i] << " ";
	cout << "\n";
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=sum; j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}
	
	return dp[n][sum];
}

int main(){
	 int n; cin >> n;
	 int arr[n];	 
	 for (int i=0; i<n; i++)
	 	cin >> arr[i];
	 
	 int sum; cin >> sum;
	 cout << knapsack(arr, n, sum) << " <=\n";  
}
