# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

/*

INPUT:
2
1A2B
3AB4C5T

OUTPUT:
ABB
ABABABCCCCTTTTT


*/


void changestr(string inp, string *out) {
	if (!(inp[0]>=48 && inp[0]<=57)) return;

	string &o = *out;
	string temp;
	int i=1; 
	
	int val = (int)inp[0] - 48;
		
	while(inp[i]>=65 && inp[i]<=90) {
		temp += inp[i]; i++; 
		
	}
	
	while(val--) o += temp;
	
	changestr(inp.substr(i), &o);
}

int main(){
	fastt;
	testt {
		string inp, out;
		cin >> inp;
		out = "";		
		
		changestr(inp, &out);
		
		cout << out << "\n"; 
	}
}
