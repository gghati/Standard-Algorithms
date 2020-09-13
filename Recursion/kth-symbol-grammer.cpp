# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

int kthele(int n , int m) {
	if (n==1 && m==1) return 0;
	
	n--;
	int val = ceil((double)m/2);
	
	int ans = kthele(n, val);
	
	if (ans==0) {
		if (m%2==0) return 1;
		else return 0;
	} else {
		if (m%2==0) return 0;
		return 1;
	}
}

int main(){
	fastt;
	
	int n, m; cin >> n >> m; 
	
	cout << kthele(n, m) << "\n";

}
