# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

/* 

Undirected Graphs

OUTPUT: 
0 -> | 1 0 | 4 0 | 
1 -> | 0 0 | 4 0 | 3 0 | 2 0 | 
2 -> | 3 0 | 1 0 | 
3 -> | 1 0 | 4 0 | 2 0 | 
4 -> | 0 0 | 1 0 | 3 0 | 
========================
0 -> | 1 1 | 4 1 | 
1 -> | 0 1 | 4 1 | 3 1 | 2 1 | 
2 -> | 3 1 | 1 1 | 
3 -> | 1 1 | 4 1 | 2 1 | 
4 -> | 0 1 | 1 1 | 3 1 |

*/


// Number of nodes
# define NODE 5
vector<int> g[NODE];
bool b[NODE] = {false};

void addEdge(int f, int t) {
	g[f].push_back(t);
	g[t].push_back(f);
}

void dfs(int n){
	if (b[n]) return;
	b[n] = true;
	vector<int> nei = g[n];
	for(auto i=nei.begin(); i!=nei.end(); i++)
		dfs(*i);
}

int main(){
    fastt;    
    
    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 4);
    addEdge(1, 3);
    addEdge(4, 3);
    addEdge(3, 2);
    addEdge(2, 1);
    
    // Print Linked List Graph
    for (int i=0;i<NODE; i++) {
    	cout << i << " -> | ";
    	for(auto j=g[i].begin(); j<g[i].end(); j++) {
    		cout << *j << " " << b[i] << " | ";
    	} cout << "\n";
    }
    
    dfs(0);
    
    cout << "========================\n";
    
    // Print Linked List Graph after DFS
    for (int i=0;i<NODE; i++) {
    	cout << i << " -> | ";
    	for(auto j=g[i].begin(); j<g[i].end(); j++) {
    		cout << *j << " " << b[i] << " | ";
    	} cout << "\n";
    }
}

