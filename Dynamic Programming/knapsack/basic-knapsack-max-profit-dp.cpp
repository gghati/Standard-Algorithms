# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second

/* 
Explaination: The reason we created a 2D dp matrix is because, if we create a recursive funtions for solving the knapsack problem then the 2 
variables that will changes(decrease in every inner call) will be W and n;
So, dp[n+1][W+1]

In dp array, we have initialized by considering the base values of W and n, 
the base value of n can be 0 and for the we will return 0 because the profit if n is 0 will be 0
same if the maximum weigth itself is 0 then the profit will also be zero

for other values, it will look at it's prev ressult like a recursion,
going from always looking at i-1 values and for j we will minus the weight if i-1 element ONLY if we include it else we just exclude it.

in both case exclude or include it will dp[i-1][...] return the value of prev element and we have to take the max value profit from it.
*/

int knapsack(int v[], int w[], int W, int n){
	int dp[n+1][W+1];
	
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=W; j++) {
			//base Condition 
			//intialization
			if (i==0 || j==0)
				dp[i][j] = 0;
			
			else {
				if (w[i-1] <= W)
					dp[i][j] = max(v[i-1] + dp[i-1][j-w[i-1]], dp[i-1][j]);
				else dp[i][j] = dp[i-1][j]; 
			}
		}
	}
	
	return dp[n][W];
}

int main(){
	fastt;
	
	int val[] = {60, 100, 120};
	int wt[] = {10, 20, 30};
	int W = 50;
	
	int n = sizeof(wt)/sizeof(wt[0]);
	
	cout << knapsack(val, wt, W, n) << endl;
	
	return 0;
}
