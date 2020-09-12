# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

// Maximum Subarray Sum => DIVIDE AND CONQUER => O(nlogn)

int three_max(int a, int b, int c) { return max( max(a, b), c ); } 

int combine(int arr[], int l, int m, int r) {
	int temp_lmax=INT_MIN;
	int sum=0;
	for(int i=m; i>=l; i--) {
		sum += arr[i];
		if(temp_lmax < sum) temp_lmax = sum;
	}
	
	int temp_rmax=INT_MIN;
	sum=0;
	for(int i=m+1; i<=r; i++) {
		sum += arr[i];
		if(temp_rmax < sum) temp_rmax = sum;
	}
	
	return three_max(temp_lmax + temp_rmax, temp_lmax, temp_rmax);
}

int max_sum(int arr[], int l, int r) {
	if (l == r) return arr[l];

	// Divide
	int m = (l+r)/2;
	
	// Conquer
	int left_max = max_sum(arr, l, m);
	int right_max = max_sum(arr, m+1, r);
	
	// Combine
	int comb_max = combine(arr, l, m, r);
	
	return three_max(comb_max, left_max, right_max);
}

int main(){
	fastt;
	int n; cin >> n;
	int arr[n];
	
	for (int i=0; i<n; i++){
		int val; cin >> val;
		arr[i] = val;
	}
	
	cout << max_sum(arr, 0, n-1);
}

