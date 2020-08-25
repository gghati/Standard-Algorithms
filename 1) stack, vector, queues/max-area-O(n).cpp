# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long

// MAX area of the rectangle who is always connected to the x-axis 

int MAX_X = 1e5;
int MAX_Y = 500;

int main(){
    fastt;
    // testt{
    
    	int N; cin >> N;
    	int max_area=0;
    	vector<pair<int, int>> p;
    	
    	for(int i=0; i<N; i++){
    		int val1, val2;
    		cin >> val1 >> val2;
    		p.push_back(make_pair(val1, val2));	
    	}
    	sort(p.begin(), p.end());
    	
	// stack algorithms for nearest smaller number
	vector<pair<int, int>> vl, vr;
    	stack<pair<int, int>> s;
    	
    	// left
    	for(int i=0; i<p.size(); i++){
    		while (!s.empty() && p[i].second <= s.top().second) s.pop();
    		if (s.empty()) vl.push_back(make_pair(0, 0));
    		else if (s.top().second < p[i].second) vl.push_back(s.top());
    		
    		s.push(p[i]);
    	}
    	
    	while(!s.empty()) s.pop();
    	    	
    	// right
	for(int i=p.size()-1; i>=0; i--){
    		while (!s.empty() && p[i].second <= s.top().second) s.pop();
    		if (s.empty()) vr.push_back(make_pair(MAX_X, 0));
    		else if (s.top().second < p[i].second) vr.push_back(s.top());
    		
    		s.push(p[i]);
    	}
    	reverse(vr.begin(), vr.end());
    	
    	for(int i=0; i<p.size(); i++){
    		pair<int, int> bn = p[i];
    		pair<int, int> l = vl[i], r = vr[i];	
    		// cout<<"("<<l.first<<" "<<l.second<<") ("<<r.first<<" "<<r.second<<")\n";
    		int area = bn.second * ( r.first - l.first );	
    		max_area = max(area, max_area);
    	}
 	
 	p.push_back(make_pair(MAX_X, 0));
 	
    	for ( int i=0; i<p.size()-1; i++ ) {
    		int area = MAX_Y * (p[i+1].first - p[i].first);
    		max_area = max(area, max_area);
   	}
    	
    	cout << max_area << "\n";
    // }
}
