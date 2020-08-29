# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

int main(){
    fastt;
	int N, M;
	cin >> N >> M;

	map<int, pair<int, int>> mp;

	vector<int> v1, v2;

	for(int i=0; i<N; i++){
		int val; cin >> val;
		v1.push_back(val);
	}	

	for(int i=0; i<M; i++){
		int val; cin >> val;
		v2.push_back(val);
	}	

	// TIME COMPLEXITY - N*N*LOGN
	int flag=0;
	for(int i=0; i<v1.size(); i++){
		for(int j=0; j<v2.size(); j++){
			mp.insert(make_pair((v1[i] + v2[j]), make_pair(i, j)));
			if (mp.size()==N+M-1) { flag=1; break; }
		}
		if(flag==1) break;
	}

	for (auto i: mp) {
		cout << i.second.first << " " << i.second.second << "\n";
	}
}
