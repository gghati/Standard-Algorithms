# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

// check number is palindrom or not

bool check(int num, int l, int r) {
	if (l >= r) return true;
	int n = num;
	
	int start = n%10,
	end=0;
		
	while(n>0) {
		end=n%10;
		n /=10;
	}
	
	if (end==start)
		return check(num, l+1, r-1);
	
	return false; 
	
}

int main(){
	fastt;
	
	int n; cin >> n;
	int m = n, cnt=0;
	
	while (m>0) {
		cnt++;
		m /= 10;
	}
	
	cout << check(n, 0, cnt) << "\n";
	
}
