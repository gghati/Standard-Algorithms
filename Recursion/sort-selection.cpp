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

void selection_sort(int arr[], int n, int p) {
	// base contition
	if (p >= n) return;
	
	p++;
	
	// logic
	int min=p;
	for (int i=p; i<n; i++)
		if(arr[i] < arr[min]) min=i;
	
	swap(&arr[p], &arr[min]);
	
	// recursion
	selection_sort(arr, n, p);
}

int main(){
	fastt;

	int n; cin >> n; 
	int arr[n];
	for (int i=0; i<n; i++) cin >> arr[i];
	
	selection_sort(arr, n, 0); 
	
	for (int i=0; i<n ;i++) cout << arr[i] << " "; 
	cout << "\n"; 
}
