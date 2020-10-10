# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void insertion_sort(int arr[], int n, int p=0) {
	// base contition
	if (p >= n-1) return;
	p++;
	
	// logic
	int i = p;
	while (arr[i] > arr[i+1] && p>=0) {
		swap(&arr[i], &arr[i+1]);
		i--;
	}
	
	// recursion
	insertion_sort(arr, n, p);
}

int main(){
	fastt;

	int n; cin >> n; 
	int arr[n];
	for (int i=0; i<n; i++) cin >> arr[i];
	
	insertion_sort(arr, n); 
	
	for (int i=0; i<n ;i++) cout << arr[i] << " "; 
	cout << "\n"; 
}
