# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

// Priority queue -> when we need sorted elements, should work like stack for pop and push
// basicly a sorted sstack
// The priority queue gquiz is :     30    20    10    5    1
// gquiz.size() : 5
// gquiz.top() : 30
// gquiz.pop() :     20    10    5    1

int main(){
    fastt;
    testt{
    	
    	int N, X;
    	cin >> N >> X;
    	priority_queue<int> s;
    	
    	while(N--){
    		int val; cin >> val;
    		s.push(val);
    	}
    	
    	int flag=0;
    	int count=0;

	while(!s.empty() && s.top() != 0){
		int var = s.top();
		cout << var << " ";
		count++;
		X -= var;
		s.pop();
		s.push(var/2);
		if(X<=0) { flag=1; break; }
	}
	
    	if(flag==0) cout << "Evacuate\n";
    	else cout << count << "\n";

    } 
}
