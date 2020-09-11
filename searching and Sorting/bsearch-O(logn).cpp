# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second


// O(logn) Algorithm.
int bsearch(int arr[], int l, int r, int ele) {
	if (r >= l) {
		// divide 
		int m = l + (r - l)/2;
		
		if (arr[m]==ele)
			return m;
		else if (arr[m] < ele)
			return bsearch(arr, m+1, r, ele);
		return bsearch(arr, l, m-1, ele);
	}
	return -1;
}

int main(){
	fastt;
	
	int N; cin >> N;
	int arr[N];
	
	// array input
	for(int i=0; i<N; i++) 
		cin >> arr[i];
	
	// find this
	int ele; cin >> ele; 
	
	int pos = bsearch(arr, 0, N-1, ele);
	
	cout << pos+1 << endl; 
}
