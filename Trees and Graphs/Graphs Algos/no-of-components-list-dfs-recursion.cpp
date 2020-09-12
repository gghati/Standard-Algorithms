# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

/* 

Undirected Graphs

0 -> 1 4 
1 -> 0 4 3 2 
2 -> 3 1 
3 -> 1 4 2 
4 -> 0 1 3 
========================
1 1 1 1 1 

*/


// Number of nodes
# define NODE 5
vector<int> g[NODE];
bool b[NODE] = {false};
int comp[NODE] = {0};

void addEdge(int f, int t) {
	g[f].push_back(t);
	g[t].push_back(f);
}

void dfs(int count, int n){
	if (b[n]) return;
	b[n] = true;
	comp[n] = count;
	
	// Search all Neighbors
	vector<int> nei = g[n];
	for(auto i=nei.begin(); i!=nei.end(); i++)
		dfs(count, *i);
}

void findComp(int count) {
	for(int i=0; i<NODE; i++)
		if (!b[i])
			count++, dfs(count, i);
}

int main(){
    fastt;    
    
    int count = 0;
    
    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 4);
    addEdge(1, 3);
    addEdge(4, 3);
    addEdge(3, 2);
    addEdge(2, 1);
    
    // Print Linked List Graph
    for (int i=0;i<NODE; i++) {
    	cout << i << " -> ";
    	for(auto j=g[i].begin(); j<g[i].end(); j++) {
    		cout << *j << " ";
    	} cout << "\n";
    }
    
    findComp(count);
    
    cout << "========================\n";
    
    // Connected Components
    for (int i=0;i<NODE; i++) {
    	cout << comp[i] << " ";
    }
    
}

