# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second
# define MEM 8

// bf => O(n3)
// Divide and Conquer => O(2^n * n)
// prefix sum then checking for each ele that any number can sum to the => O(n2)

// THIS CODE IS // kadane's algorithm => O(n)

int main() {
	fastt; 
	
	int n; cin >> n;
	int arr[n];
	
	for (int i=0; i<n; i++) cin >> arr[i];	
	
	int meh=0;	// maximum sum here
	int msf=INT_MIN;  // maximum sum so far
	
	for (int i=0; i<n; i++) {
		meh = meh + arr[i];
		if (meh < arr[i]) 
			meh = arr[i];
		if (msf < meh) 
			msf = meh;
	}
	
	cout << msf << endl;
	return 0;
} 
