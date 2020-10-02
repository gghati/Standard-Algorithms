# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second
# define MEM 8

// bf => O(n2) 
// 

int main() {
	fastt; 
	
	int n, val; cin >> n; 
	
	vector<pair<int, int>> arr;
	for(int i=0; i<n; i++) { 
		cin >> val;
		arr.push_back(make_pair(val, i+1)); 
	}
	
	stack<pair<int, int>> stk;
	vector<int> pos;	
	
	for (int i=0; i<n; i++) {
		if (stk.empty()) {
			stk.push(arr[i]);	
			pos.push_back(0);
		}
		else {
			while (!stk.empty() && (stk.top().ff >= arr[i].ff) )
				stk.pop();
			
			if (stk.empty())	
				pos.push_back(0);
			else pos.push_back(stk.top().ss);
			stk.push(arr[i]);
		}
	}
	
	for(int i=0; i<pos.size(); i++) cout << pos[i] << " "; 
	
	return 0;
} 
