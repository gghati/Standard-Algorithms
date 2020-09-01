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
    	deque<pair<int, int>> points;
    	
    	for(int i=0; i<N; i++){
    		int val1, val2;
    		cin >> val1 >> val2;
    		points.push_back(make_pair(val1, val2));	
    	}
 	
    	for(int i=0; i<points.size(); i++){
    		pair<int, int> bn = points[i];
    		pair<int, int> l = make_pair(0, bn.second),
    		r = make_pair(MAX_X, bn.second);
    		
    		for(int j=i+1; j<points.size() ;j++){
    			if( bn.second >= points[j].second) {
    				r = points[j]; break;
    			}
    		}
    		
    		for(int j=i-1; j>=0; j--){
    			if( bn.second >= points[j].second) {
    				l = points[j]; break;
    			}
    		}
    		
    		int area = bn.second * ( r.first - l.first );
    		
    		max_area = max(area, max_area);
    	}
 	
 	points.push_front(make_pair(0, 0));
 	points.push_back(make_pair(MAX_X, 0));
 	
    	for ( int i=0; i<points.size()-1; i++ ) {
    		int area = MAX_Y * (points[i+1].first - points[i].first);
    		max_area = max(area, max_area);
   	}
    	
    	cout << max_area << "\n";
    // }
}
