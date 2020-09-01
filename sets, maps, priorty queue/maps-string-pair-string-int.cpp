# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

int main(){
    fastt;
    // testt{
    	
    	int N, M;
    	cin >> N >> M;
    	
    	map<string, int> ctrys;
    	map<string, pair<string, int>> chefs;
    	
    	// LOGN
    	for(int i=0; i<N; i++) {
    		string name, ctry;
    		cin >> name >> ctry;
    		ctrys.insert(make_pair(ctry, 0));
    		chefs.insert(make_pair(name, make_pair(ctry, 0)));
    	}
    	
    	for(int i=0; i<M; i++) {
    		string vote;
    		cin >> vote;
    		
    		(chefs[vote].ss)++;
    		ctrys[chefs[vote].ff]++;
    	} 
    	
    	int max_cont=0;
    	string str_max_cont=(*ctrys.begin()).ff;
    	
    	for(auto i=ctrys.begin(); i!=ctrys.end(); i++) {
    		if (max_cont < (*i).ss) {
    			max_cont = (*i).ss;
    			str_max_cont = (*i).ff;
    		}
    	}
    	
    	int max_chef=0;
    	string str_max_chef = (*chefs.begin()).ff;
    	for(auto i=chefs.begin(); i!=chefs.end(); i++) {
		if (max_chef < (*i).ss.ss) {
			max_chef = (*i).ss.ss;
			str_max_chef = (*i).ff;
    		}	
    	}
    	
    	cout << str_max_cont << "\n";
    	cout << str_max_chef << "\n";
    	
    //}
}
