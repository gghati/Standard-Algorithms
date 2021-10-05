# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second
 
# define NODE 200003
 
vector<int> tree[NODE];
int b[NODE] = {0}; 
 
 
void dfs(int n) {
	b[n] = 1; 	
	for (auto i: tree[n]) {
		dfs(i); 
		b[n] += b[i];
	}
}
 
 
int main() {
	fastt;
	
	int n; cin >> n;
	for (int i=2; i<=n; ++i) {
		int p; cin >> p; 
		tree[p].push_back(i);
	}
 
	dfs(1); 
	
	for(int i=1; i<=n; i++)
		cout << b[i]-1 << " "; 
	
	return 0;
}
