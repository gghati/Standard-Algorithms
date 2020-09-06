# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second
# define pb push_back
 
 
# define NODE 100002
 
vector<int> arr[NODE];
int c[NODE] = {0};
bool vis[NODE] = {false};
int ctn=0;
 
void addEdge(int a, int b) {
	arr[a].pb(b);
	arr[b].pb(a);
}
 
void dfs(int s) {	
	if (vis[s]) return;
	vis[s] = true;
 
	if (c[s]==0) c[s] = 1;
 
	vector<int> nei = arr[s];
	
	for(auto i=nei.begin(); i!=nei.end(); i++) {
		if (c[s] == c[*i]) { ctn=1; return; }
		if (c[s] == 1) c[*i] = 2;
		else if (c[s] == 2) c[*i] = 1;
		dfs(*i);
	}
}

int main(){
	fastt;
	
	int n, m;
	cin >> n >> m;
	
	for (int i=0; i<m; i++)  {
		int val1, val2;
		cin >> val1 >> val2;
		addEdge(val1, val2);
	}
	
	for (int i=1; i<=n; i++)
		if(c[i]==0) dfs(i);

	if (ctn==1) cout << "IMPOSSIBLE\n";
	else {
		for (int i=1; i<=n; i++)
			cout << c[i] << " ";
		cout << "\n";
	}
}

