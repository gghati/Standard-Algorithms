# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

// output 220

// Recursion Code

int knapsack(int W, int v[], int w[], int n){

	// base Condition
	if (W==0 || n==0) return 0;
	
	// if weight is greater then not selected.
	if (w[n] > W) return knapsack(W, v, w, n-1);
	
	// comparing 
	return max( v[n] + knapsack(W-w[n], v, w, n-1),  
				knapsack(W, v, w, n-1));
	
}

int main(){
	fastt;
	
	int val[] = {60, 100, 120};
	int wt[] = {10, 20, 30};
	int W = 50;
	
	int n = sizeof(wt)/sizeof(wt[0]);
	
	cout << knapsack(W, val, wt, n) << endl;
	
	return 0;
}
