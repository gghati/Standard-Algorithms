# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second
# define MEM 8

// bf => 	four fixed elements O(n4)
// 2nd bf => two fixed ele then two pointer in the pair => O(n3)
// efficient => pair them and then apply two pointer in the pair O(n2) 

int main() {
	fastt; 
	
	int n, sum; cin >> n >> sum;
	int arr[n];
	for (int i=0; i<n; i++)
		cin >> arr[i];
	
	vector<pair<int, pair<int, int>>> pairsum; 
	
	for (int i=0; i<n; i++) 
		for (int j=i+1; j<n; j++) 
			pairsum.push_back( make_pair(arr[i] + arr[j], make_pair(i+1,j+1)) );
	
	
	int l=0;
	int r=pairsum.size()-1; 
	sort(pairsum.begin(), pairsum.end());
	
	while(l<r) {
		if (pairsum[l].ff + pairsum[r].ff == sum) {
			if (pairsum[l].ss.ss != pairsum[r].ss.ss) 
				cout << pairsum[l].ss.ff << " " << pairsum[l].ss.ss << " "
				<< pairsum[r].ss.ff << " " << pairsum[r].ss.ss << endl; 
			else cout << "IMPOSSIBLE" << endl;
			return 0;	
		}
		
		if (pairsum[l].ff + pairsum[r].ff < sum) 
			++l;
		else --r;
	}
	
	cout << "IMPOSSIBLE" << endl;
	return 0;
}
