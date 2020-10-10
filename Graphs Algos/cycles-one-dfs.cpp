# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second
 
# define NODE 100002
 
vector<int> arr[NODE];
bool vis[NODE] = {false};
int pv[NODE]; 
int ctn=0;
vector<int> ans;

void addEdge(int a, int b){
	arr[a].push_back(b);
	arr[b].push_back(a);
}

void dfs(int s, int prev=-1) {
	pv[s] = prev;
	vis[s] = 1;
	
	for(int nei: arr[s]) {
		// leave the parent node
		if(nei==prev) 
			continue;
			
		// if it's visited then
		if (vis[nei]) {
			int s2 = s;
			
			// back track all the previous elements
			while (s^nei) {
				ans.push_back(s);
				s = pv[s];
				//cout << s << " " << nei << " => " << (s^nei) << "\n";
			}
			
			ans.push_back(nei);
			ans.push_back(s2);
			cout << ans.size() << "\n";
			
			// print all the cycle element
			for(int a: ans)
				cout << a << " ";
			
			// Exit the program.
			exit(0);
		} 
		
		else dfs(nei, s);
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
	
	
	for (int i=1; i<=n; i++) {
		if (!vis[i])
			dfs(i);
	}
	
	cout << "IMPOSSIBLE";
}
