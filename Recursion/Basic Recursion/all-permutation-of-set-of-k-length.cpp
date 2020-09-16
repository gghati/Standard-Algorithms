# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

/* Print all possible strings of length k that can be formed from a set of n characters

INPUT:
3
ab

OUTPUT:
aaa
aab
aba
abb
baa
bab
bba
bbb

*/


void print(string inp, int k, string curstr, vector<string> *out){

	// base case
	if (k==0) {
		(*out).push_back(curstr);
		return;
	}
	
	for(char i: inp)
		print(inp, k-1, (string) curstr+i, &(*out));
		
}


int main(){
	fastt;
	
	string inp;
	int k, val;
	cin >> k; 
	
	cin >> inp; 
	
	vector<string> out;
	
	print(inp, k, "", &out);
	
	for(int i=0; i<out.size(); i++)
		cout << out[i] << "\n";
}
