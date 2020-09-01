# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

/*

Shortest path from A to B in Array graphs





*/

const int MAX=1e3;

int n, m, ai, aj, bi, bj;
string s[MAX];

string str;

bool e(int i, int j) {
	return (i>=0 && i<n && j>=0 && j<m && s[i][j]=='.');
}

void dfs(int i, int j) {
	if(s[i][j]=='B') flag=true;
	else s[i][j]='#';
	if(e(i+1, j))
		dfs(i+1, j);
	if(e(i, j+1))
		dfs(i, j+1);
	if(e(i-1, j))
		dfs(i-1, j);
	if(e(i, j-1))
		dfs(i, j-1);
}

int main(){
    fastt;
    
    cin >> n >> m;

    for(int i=0; i<n; i++) {
    	cin >> s[i];
    	if(s[i] == 'A'){
    		
    	} else if (s[i] == 'B') {
    		
    	}
    }
    	
    int ans=0;
    for(int i=0;i<n;i++)
 	   for(int j=0; j<m; j++)
		if(s[i][j] == 'A')
			dfs(i, j), ++ans;
    
    cout << ans << "\n";
 	
}

