# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

int main() {
	fastt;
	
	// 3th bit
	int n=3; 
	n--;
	
	int num=9; // 1001	
		   
	// get if ith bit. 
	cout << ( ( num & (1 << n) ) >> n ) << endl;
	// ans => 0
	
	// set the ith bit to 1
	cout << (num|(1 << n)) << endl;
	// ans => 1101 => 13
	
	// clear the ith bit
	cout << ( num & (~(1<<n)) ) << endl; 
	// ans => 1001 => 9 
	
	// update the ith bit => 0 to 1 and 1 to 0
	cout << ( num^(1<<n) ) << endl;
	// ans => 1101 => 13
	
	
	return 0;
}


