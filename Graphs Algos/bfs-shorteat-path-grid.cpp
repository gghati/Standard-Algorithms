# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

// Number of nodes
# define MAXN 1001
# define MAXM 1001

char s[MAXN][MAXM];
vector<char> path;

//void findpath(pair<int, int> a, pair<int, int> b, pair<int, int> pv[]){}

void solve(pair<int, int> a) {
	queue<pair<int, int>>	q;
	q.push(a);
	
	while(!q.empty()) {
		pair<int, int> node = q.front();
		q.pop();
		int i = node.ff, j = node.ss;
		
		if (i!=0 && s[i-1][j] == '.')
			q.push(make_pair(i-1, j)),
			s[i-1][j] = 'U';
		
		if (i!=MAXN && s[i+1][j] == '.' )
			q.push(make_pair(i+1, j)),
			s[i+1][j] = 'D';
		
		if (j!=0 && s[i][j-1] == '.' )
			q.push(make_pair(i, j-1)),
			s[i][j-1] = 'L';
		if (j!=MAXM && s[i][j+1] == '.' )
			q.push(make_pair(i, j+1)),
			s[i][j+1] = 'R';
	}
}

void findpath(pair<int, int> a, pair<int, int> b) {
	while (true) {
		int i = b.ff;
		int j = b.ss;
					
		if (s[i][j] == 'A')
			break;
		
		if (s[i][j] == '#'){
			path.clear();
			break; 
		}
		
		path.push_back(s[i][j]);
		
		if (s[i][j] == 'U')
			b.ff+=1;
		else if (s[i][j] == 'D')
			b.ff-=1;
		else if (s[i][j] == 'R')
			b.ss-=1;
		else if (s[i][j] == 'L')
			b.ss+=1;
		else{ 
			path.clear();
			break; 
		}
	}
	
	reverse(path.begin(), path.end());
}

void bfs(pair<int, int> a, pair<int, int> b){
	solve(a);
	findpath(a, b);
}

int main(){
    fastt;
    
    int n, m, ai=0, aj=0, bi=0, bj=0;
    cin >> n >> m;
        
    for (int i=0; i<n; i++){
    	cin >> s[i];
    	for(int j=0; j<m; j++) {
    		if(s[i][j] == 'A')
    			ai = i, aj = j;
    		if(s[i][j] == 'B')
    			s[i][j] = '.', bi = i, bj = j;
    	}
    }
    
    bfs(make_pair(ai, aj), make_pair(bi, bj));
    
/*    for (int i=0; i<n; i++) {
    	for(int j=0; j<m; j++)
		cout << s[i][j];
	cout << "\n";
    } */

	if (path.size()==0) 
		cout << "NO\n";
	else {
	    cout << "YES\n";
	    cout << path.size() << "\n";
	    for(int i=0; i<path.size(); i++)
	    	cout << path[i];
	    cout << "\n";
    	}
}
