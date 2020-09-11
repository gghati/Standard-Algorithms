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

int part(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low;
	int j = high;
	
	while (j > i) {
		while(arr[i] < pivot) i++ ;
		while(arr[j] > pivot) j--;
		swap(&arr[i], &arr[j]);
	}
	return i;
}


void quick_sort(int arr[], int l, int r) {
	if (r > l) {
		int p = part(arr, l, r);
		
		// p element is already sorted don't need to 
		// sort it by sending in quick sort again. 
		quick_sort(arr, l, p-1);
		quick_sort(arr, p+1, r);
	}
}


int main(){
	fastt;
	
	// 15, 3, 9, 8, 5, 2, 7, 1, 6
	int N; cin >> N;
	int arr[N];
	
	// array input
	for(int i=0; i<N; i++) 
		cin >> arr[i];
		
	quick_sort(arr, 0, N-1);
	
	for(int i=0; i<N; i++) 
		cout << arr[i] << " ";
	cout << "\n";
}
