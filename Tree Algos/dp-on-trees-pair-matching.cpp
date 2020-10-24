# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second
 
// read the problem statement here - https://cses.fi/problemset/task/1130/
 
# define NODE 200003
 
vector<int> t[NODE];
int dp[NODE][2];
 
void dfs(int u, int p=-1) {
	for (int v: t[u]) {
		if (v==p) continue; 
		dfs(v, u);
		dp[u][1] = max(dp[u][1]+max(dp[v][0], dp[v][1]), dp[u][0]+dp[v][0]+1); 
		dp[u][0] += max(dp[v][0], dp[v][1]); 
	}
}
 
int main() {
	fastt;
	
	int n; cin >> n;
	for (int i=1; i<n; i++)	{
		int l, p; cin >>l >> p;	 
		t[l].push_back(p); 
		t[p].push_back(l); 
	}
	
	dfs(1); 	
	
	cout << max(dp[1][0], dp[1][1]) << endl; 
	return 0;
}
