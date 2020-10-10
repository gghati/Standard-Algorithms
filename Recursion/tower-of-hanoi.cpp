# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

// Tower of Hanio

void solve(int s, int d, int h, int n, int *count) {
	int &ct = *count;
	
	ct++;
	// base condition
	if (n==1) { 
		cout << "moving plate 1 from " << s << " to " << d << "\n"; 
		return; 
	}
	
	// 1st to (n-1)th from 1 => 2
	solve(s, h, d, n-1, &ct);
	cout << "moving plate " << n << " from " << s << " to " << d << "\n"; 
	
	// 1st to (n-1)th from 2 => 3
	solve(h, d, s, n-1, &ct);
}

int main(){
	fastt;
	
	int n; cin >> n; 
	
	int s=1, h=2, d=3; 
	// number of steps
	int count = 0; 
	
	solve(s, d, h, n, &count);
	
	cout << count << "\n";
}
