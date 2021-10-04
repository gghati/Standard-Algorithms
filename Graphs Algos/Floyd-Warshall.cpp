//Floyd Warshall Algorithm
//ALL Pairs Shortest Path problem - The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph.
//Time Complexity : O(V^3) //V number of vertices
//Space Complexity : O(V^2)

int dist[N][N];

void FloydWarshall()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

/*

#include <bits/stdc++.h>
using namespace std;
 
#define bolt ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N=1e3+5;
 
int n;
int dist[N][N];

void FloydWarshall()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

 
int32_t main()
{
	bolt;
	cin>>n;

	for(int i=1;i<=n;i++){
        for(int j = 1;j<=n; j++){
            int u; cin >> u;
            dist[i][j] = u;
        }
    }
     
    FloydWarshall();
    
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=n; j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
	
	return 0;
}

input : 
4
0 5 99999 10
99999 0 3 99999
99999 99999 0 1
99999 99999 99999 0

Output :
0 5 8 9 
99999 0 3 4 
99999 99999 0 1 
99999 99999 99999 0 
*/