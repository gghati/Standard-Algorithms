# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second
// Number of nodes
# define NODE 5

/* 

BFS => SHORTEST path Algorithms

OUTPUT:

0 -> 1 4 
1 -> 0 4 3 2 
2 -> 3 1 
3 -> 1 4 2 
4 -> 0 1 3 
============
SHOERTEST PATH BETWEEN 0-2  => (0 1 2)

*/

vector<int> g[NODE];
bool b[NODE] = {false};
int pv[NODE];
vector<int> path;

void addEdge(int f, int t) {
	g[f].push_back(t);
	g[t].push_back(f);
}

void solve(int s) {
	queue<int> q;
	q.push(s);
    	b[s]=true;
    	cout << "============\n";
	while (!q.empty()) {
		int node = q.front();	
		q.pop();
		vector<int> nei = g[node];

		for (auto i: nei)
			if (!b[i]) {
				q.push(i);
				b[i] = true;
				pv[i] = node;
			}
	}
}

void trackpath(int s, int e ) {
	for(int i=e; i!=(-1); i=pv[i])
 		path.push_back(i);
		
	reverse(path.begin(), path.end());
	
	if (path[0] != s)
		path.clear();
} 

void bfs(int s, int e) {
	solve(s);
	trackpath(s, e);
}

int main(){
    fastt;
    
    int count = 0;
    
    for(int i=0; i<NODE; i++)
    	pv[i] = -1;    
    
    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 4);
    addEdge(1, 3);
    addEdge(4, 3);
    addEdge(3, 2);
    addEdge(2, 1);
    
    // Print List Graph
    for (int i=0;i<NODE; i++) {
    	cout << i << " -> ";
    	for(auto j=g[i].begin(); j<g[i].end(); j++)
    		cout << *j << " ";
    	cout << "\n";
    }
    
    bfs(0, 2);
    
    for(int i: path)
    	cout << i << " ";
    cout << endl;
}
