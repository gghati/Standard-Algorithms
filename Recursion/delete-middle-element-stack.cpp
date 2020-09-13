# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

void delete_middle(stack<int> *stk, int size) {
	stack<int> &s1 = *stk;
	
	// base condition
	if (s1.empty()) return; 
	
	if (s1.size()==size) {
		s1.pop();
		return;
	}
	
	int up = s1.top();
	s1.pop();
	
	// recursion
	delete_middle(&s1, size);
	
	s1.push(up);
}

int main(){
	fastt;

	int n; cin >> n; 
	stack<int> stk;
	for (int i=0; i<n; i++){ 
		int val; cin >> val;
		stk.push(val);
	}
	
	delete_middle(&stk, (stk.size()/2 + 1)); 
	
	while(!stk.empty()){
		int val = stk.top();
		stk.pop();
		cout << val << " ";
	}
	cout << "\n"; 
}
