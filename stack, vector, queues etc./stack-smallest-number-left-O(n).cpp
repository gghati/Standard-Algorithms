# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long

int main(){
    fastt;
    	int N, K;
    	cin >> N >> K;
    	stack<pair<int, int>> s;
    	vector<int> v;
    	
    	for(int i=0;i<N;i++){
    		int val;
    		cin >> val;
    		v.push_back(val);
    	}
    	
    	ll  pro=1;
    	
    	for(int i=N-1; i>=0; i--){
    		while(!s.empty() && s.top().first >= v[i]){
    			s.pop();
    		}
    		
    		if(s.empty())
    			pro *= 1;
    		
    		else if(s.top().first < v[i]){
    			pro *= (s.top().second - i + 1);
    			pro %= 1000000007;
    		}
    			
    		s.push(make_pair(v[i], i));
    	}
    	
      	cout << pro << "\n";
}
