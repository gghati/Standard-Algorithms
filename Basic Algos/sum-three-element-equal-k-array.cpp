# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second
# define MEM 8
 
// efficient => 1 fixed elements then two pointer => O(n2)
// bf => three fixed number => O(n3) 
 
int main() {
	fastt; 
	
	int n, x; cin >> n >> x; 
	array<int, 2> arr[n];
	
	for (int i=0; i<n; i++) { 
		cin >> arr[i][0]; 
		arr[i][1] = i+1; 
	}
 
	sort(arr, arr+n);
	for (int i=0; i<=n; i++) {
		int l = i+1; 
		int r = n-1;
		
		while(l<r) {
			if (arr[i][0] + arr[l][0] + arr[r][0] == x) {
				cout << arr[i][1] << " " << arr[l][1] << " " << arr[r][1] << endl;
				return 0; 
			}
			if( arr[i][0] + arr[l][0] + arr[r][0] < x )
				l++;
			else 
				r--; 
		}
	}	
	
	cout << "IMPOSSIBLE";
	return 0;
}
