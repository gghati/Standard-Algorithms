# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

void sort_stack(stack<int> *stk) {
	stack<int> &s1 = *stk;
	if (s1.empty()) return; 
	
	// logic
	int up = s1.top();	
	s1.pop();
	
	stack<int> s;
	
	sort_stack(&s1);
	
	while(!s1.empty() && s1.top()>up) {
		s.push(s1.top());
		s1.pop();
	}
	
	s1.push(up);
	
	while(!s.empty()) {
		s1.push(s.top());
		s.pop();
	}
}

int main(){
	fastt;

	int n; cin >> n; 
	stack<int> stk;
	for (int i=0; i<n; i++){ 
		int val; cin >> val;
		stk.push(val);
	}
	
	sort_stack(&stk); 
	
	while(!stk.empty()){
		int val = stk.top();
		stk.pop();
		cout << val << " ";
	}
	cout << "\n"; 
}
