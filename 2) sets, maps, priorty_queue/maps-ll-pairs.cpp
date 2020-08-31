# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

ll NUM=1e10;

int main(){
    fastt;
    testt{
    	int N, M, K;
    	cin >> N >> M >> K;
    	    	
    	map<ll, pair<int, int>> p;

    	for (int j=0; j<K; j++){
    		int val1, val2;
    		cin >> val1 >> val2;
		ll sum= (val1*NUM) + val2;
		cout << sum << "\n";
    		p.insert(make_pair(sum, make_pair(val1, val2)));
    	} 
    	
    	int count=0;   
    	for (auto i=p.begin(); i!=p.end(); i++){
    		int val1 = (*i).ss.ff;
    		int val2 = (*i).ss.ss;
    		
    		ll sum1=((val1+1)*NUM)+val2;
    		ll sum2=(val1*NUM)+(val2+1);
    		ll sum3=((val1-1)*NUM)+val2;
    		ll sum4=(val1*NUM)+(val2-1); 
    		
		if (p.find(sum1) == p.end()) count++;
		if (p.find(sum2) == p.end()) count++;
		if (p.find(sum3) == p.end()) count++;
		if (p.find(sum4) == p.end()) count++;

    	}
    	cout << count << "\n";
    }
}
