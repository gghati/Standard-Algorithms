# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

const int M = 1e9+7, mxN=100, mxX=1e6; 
ll dp[mxX+1];
int arr[mxN], n, sum;
 
int main() {
	fastt;
	
	cin >> n >> sum;
	
	for (int i=0; i<n; i++) cin >> arr[i];
	
	dp[0] = 1;
	
	for (int i=1; i<=sum; i++) {
		for(int j=0; j<n; j++) {
			if (arr[j]<= i)
				dp[i] = (dp[i]+dp[i-arr[j]])%M;
		}
	}
	
	cout << dp[sum] << "\n";
	
	return 0;
}

