# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

// subset sum
// You are given numbers. Check if there is a subset of them, with the sum equal to target value S
// N<=20

// This is B.F. algo - O(2^N. N)
// By Dp it can go till O(n^2)

int main() {
	fastt;
	
	int n=5;
	
	int a[] = {2, 3, 4, 1, 5};
	int S = 7;
	
	for (int i=0; i<(1<<n); i++) {
		ll sum = 0; 
		for (int j=0; j<n; j++) {
			if (i & (1<<j))
				sum += a[j];
		}
		if (sum==S) {
			cout << "Yes!" << endl;
			return 0; 
		}
	}
	
	cout << "No" << endl; 
	return 0;
}
