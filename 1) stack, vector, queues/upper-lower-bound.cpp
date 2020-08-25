# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long

// Upper and lower bound are better than binary search 

int fun1(vector<int> v, int x, int check){
	int l=0;
	int r=v.end()-v.begin()-1;
	while (l<=r) {
		int m = l + (r-l)/2;
		if (v[m]==x) return (m);
		if (v[m] < x) l = m + 1;
		else r = m - 1;
	}
	if(check==1) return r;
	return l;
}

int main(){
    fastt;
//    testt{
    	int N, V, W;
    	cin >> N >> V >> W;
    	vector<pair<int, int>> con;
    	vector<int> v1, v2;
    	
    	for(int i=0;i<N;i++){
    		int val1, val2;
    		cin >> val1 >> val2;
    		con.push_back(make_pair(val1, val2));
    	}
    	
    	for(int i=0;i<V;i++){ 
    		int val; cin >> val; 
    		v1.push_back(val);
    	}
    	
    	for(int i=0;i<W;i++){ 
    		int val; cin >> val; 
    		v2.push_back(val);
    	}
    	
    	sort(v1.begin(), v1.end());
    	sort(v2.begin(), v2.end());  	
    	int min_dur=INT_MAX;
  	
  	//cout << "\n----------\n";
    	for(auto i : con){
    		if(i.first < *v1.begin() || i.second> *(--v2.end())) continue;
    		
    		// int it1 = fun1(v1, i.first, 1);
    		// int it2 = fun1(v2, i.second, 2);
   		
    		int it1 = upper_bound(v1.begin(), v1.end(), i.first) - v1.begin();
    		int it2 = lower_bound(v2.begin(), v2.end(), i.second) - v2.begin();
    		//if(v1[it1]==i.first) it1--;
    				
		if (it1!=0 && it2!=W) {
			//cout << v1[it1-1] << " " << v2[it2] << "\n";
	    		int val=(v2[it2] - v1[it1-1] + 1);
	    		min_dur = min(val, min_dur);
    		}
    	}
    	
    	cout << min_dur << "\n";
  //  }
}
