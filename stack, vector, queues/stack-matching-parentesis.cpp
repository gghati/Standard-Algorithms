# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long

int main(){
    fastt;
//    testt{
    
    	int N;
    	cin >> N;
    	
    	stack<int> s;
    	vector<int> v;
    	v.push_back(0);
    	
    	int max_dep=0, pos_max=0, max_len=0, len_pos=0;
    	
    	for(int i=0; i<N; i++){
    		int val;
    		cin >> val;
    		if(val==1)s.push(1);
    		else if(val==2)s.pop();
    		
    		if(s.size() > max_dep){
    			max_dep = s.size();
    			pos_max=i+1;
    		}
    		
    		if(s.empty())	v.push_back(i+1);
    		
    	}
    	
    	for(int i=0; i<v.size()-1; i++){
    		if(v[i+1]-v[i] > max_len){
    			max_len = v[i+1] - v[i];
    			len_pos=v[i]+1;
    		}
    	}
    	cout << max_dep << " " << pos_max << " " << max_len << " " << len_pos << "\n";
}
