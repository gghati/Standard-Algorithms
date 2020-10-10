# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

// MERGE SORT => DIVIDE AND CONQUER


void merge(int arr[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	
	int L[n1];
	int R[n2];
	
	for(int i=0; i<n1; i++)
		L[i] = arr[l+i];
	for(int i=0; i<n2; i++)
		R[i] = arr[m+1+i];
		
	int i=0, j=0, k=l;
	while(i<n1 && j<n2) {
		if(L[i] <= R[j]) {
			arr[k]	= L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}	
	
	while(i < n1) {
		arr[k]	= L[i];
		i++, k++;
	}
	
	while(j < n2) {
		arr[k]	= R[j];
		j++, k++;
	}
}

void merge_sort(int arr[], int l, int r) {
	if (l < r) {
		// Divide
		int m = l + (r-l)/2;
		
		// Conquer
		merge_sort(arr, l, m);
		merge_sort(arr, m+1, r);
		
		// Combine
		merge(arr, l, m, r);
	}
}

int main(){
	fastt;
	int n; cin >> n;
	int arr[n];
	
	for (int i=0; i<n; i++){
		int val; cin >> val;
		arr[i] = val;
	}
	
	merge_sort(arr, 0, n-1);
	
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

