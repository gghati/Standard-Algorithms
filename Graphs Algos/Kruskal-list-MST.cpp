# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

// Kruskal’s Minimum Spanning Tree Algorithm

# define NODE 2002

// overall graph
vector<pair< int, pair<int, int>>>  mp;

// Disjoint sets
int par[NODE] = {0};
int ran[NODE] = {0};


int find(int n) {
	if (n != par[n]) 
		par[n] = find(par[n]);
	return par[n]; 
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	
	if (ran[x] > ran[y])
		par[y] = x;
	else 
		par[x] = y; 
	
	if (ran[x]==ran[y])
		ran[y]++;
}

int main() {
	fastt; 
	
	mp.push_back({ 1, {7, 6}});
	mp.push_back({ 2, {8, 2}});
	mp.push_back({ 2, {6, 5}});
	mp.push_back({ 4, {9, 1}});
	mp.push_back({ 4, {2, 5}});
	mp.push_back({ 6, {8, 6}});
	mp.push_back({ 7, {2, 3}});
	mp.push_back({ 7, {7, 8}});
	mp.push_back({ 8, {9, 7}});
	mp.push_back({ 8, {1, 2}});
	mp.push_back({ 9, {3, 4}});
	mp.push_back({ 10, {5, 4}});
	mp.push_back({ 11, {1, 7}});
	mp.push_back({ 14, {3, 5}});
	
	for(int i=0; i<=mp.size(); i++) par[i] = i;
	
	// O(nlogn) 	
	sort(mp.begin(), mp.end());
	//reverse(mp.begin(), mp.end()); 
	
	int ans=0; 	
	for (auto i: mp) {
		int u = find(i.ss.ff);
		int v = find(i.ss.ss); 
		
		if (u != v) {
			ans += i.ff; 	
			merge(u, v);
		}
	}
	
	cout << ans << endl;
	return 0;
}
