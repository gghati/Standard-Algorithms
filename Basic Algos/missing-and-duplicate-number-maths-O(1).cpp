# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second
# define MAX 1002

int main() {
	fastt;
	testt {
		
		int n; cin >> n;
		
		int arr[n];
		int sum=0, sum2=0;
		
		for(int i=0; i<n; i++) { 
			cin >> arr[i];
			sum += arr[i];
			sum2 += arr[i]*arr[i];
		}
		
		int isum = n*(n+1)/2;
		int isum2 = n*(n+1)*(2*n+1)/6;

		// 1 4 3 4 5
		// a => removed (2)
		// b => repeated (4)
		// b - a = sum - isum  --- (i)
		// b2 - a2 = sum2 - isum2
		
		// b + a = (sum2 - isum2)/(sum - isum)  --- (ii)
		
		// b = (i + ii) / 2
		// a = |i - ii| / 2
		
		int c1 = sum - isum;
		int c2 = (sum2 - isum2)/(sum - isum);
		
		cout << ( c1 + c2 )/2 << "\n"; 
		cout << (c2-c1)/2 << "\n"; 
	}
			
	return 0;
}
