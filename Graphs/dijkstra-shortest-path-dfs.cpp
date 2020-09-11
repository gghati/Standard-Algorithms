# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

// Dijkstra’s shortest path algorithm
// store the minimum distance from one node to the every other node.


# define NODE 100002

vector<pair<ll, ll>> arr[NODE];
ll d[NODE];

int main(){
	fastt;
	
	int n, m;
	cin >> n >> m; 
	
	for (int i=0; i<m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back({c, b});
	}
	
	priority_queue<pair<ll, ll>, std::vector<pair<ll, ll>>, greater<pair<ll, ll>> > pq;
	
	pq.push({0, 1});
	
	memset(d, 0x3f, sizeof(d));	
	d[1] = 0;
	while (pq.size()) {
		pair<ll, ll> p = pq.top(); // p.ff => dist, p.ss => index
		pq.pop(); 
		
		// leave the element which is already fixed.		
		if (d[p.ss] < p.ff)
			continue;
			
		for(auto nei: arr[p.ss]) {
			if (d[nei.ss] > (nei.ff+d[p.ss]) ) {
				d[nei.ss] = nei.ff + d[p.ss];
				pq.push({ d[nei.ss], nei.ss });
			}
		}
	}
	
	for (int i=1; i<=n; i++)
		cout << d[i] << " ";
	cout << "\n";
} 
