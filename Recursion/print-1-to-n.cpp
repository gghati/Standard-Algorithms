# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

void print_1ton(int n) {
	if (n == 0)
		 return;
	print_1ton(n-1);
	cout << n << " ";
}

void print_nto1(int n) {
	if (n == 0)
		 return;
	cout << n << " ";
	print_nto1(n-1);
}

int main(){
	fastt;

	int n; cin >> n;
	print_1ton(n);
	cout << "\n";
	print_nto1(n);

}
