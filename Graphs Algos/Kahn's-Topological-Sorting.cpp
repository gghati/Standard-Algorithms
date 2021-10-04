// Kahn’s algorithm for Topological Sorting
//Time Complexity : O(V + E) //V number of vertices, E = number of edges

int in[N];
vector<int> topo; //Stores lexicographically smallest toposort
vector<int> g[N];

bool toposort() //Returns 1 if there exists a toposort, 0 if there is a cycle
{
    priority_queue<int, vector<int>, greater<int>> pq;
    //priority_queue<int> pq; // To find any topological sort

    for (int i = 1; i <= n; i++)
        for (auto &it : g[i])
            in[it]++;
    for (int i = 1; i <= n; i++)
    {
        if (!in[i])
            pq.push(i);
    }
    while (!pq.empty())
    {
        int u = pq.top();
        pq.pop();
        topo.push_back(u);
        for (auto &v : g[u])
        {
            in[v]--;
            if (!in[v])
                pq.push(v);
        }
    }
    if (topo.size() < n)
        return 0;
    return 1;
}
/*--------------------------------------------------
                Example
//Problem : https://www.spoj.com/problems/TOPOSORT/
//Solution : 

#include <bits/stdc++.h>
using namespace std;
 
#define bolt ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N=1e5+5;
 
int n, m;
int in[N];  //indegree of nodes
vector<int> topo; 
vector<int> g[N];   
 
bool toposort() //Returns 1 if there exists a toposort, 0 if there is a cycle
{	
	priority_queue<int, vector<int>, greater<int> > pq; //min heap - Stores lexicographically smallest toposort
	for(int i=1;i<=n;i++)
		for(auto &it:g[i])
			in[it]++;

	for(int i=1;i<=n;i++)
	{
		if(!in[i])
			pq.push(i);
	}
	while(!pq.empty())
	{
		int u=pq.top();
		pq.pop();
		topo.push_back(u);
		for(auto &v:g[u])
		{
			in[v]--;
			if(!in[v])
				pq.push(v);
		}
	}
	if(topo.size()<n)
		return 0;
	return 1;
}
 
int32_t main()
{
	bolt;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
	}
	if(toposort())
		for(auto &it:topo)
			cout<<it<<" ";
	else
		cout<<"Sandro fails.";
	return 0;
}
*/