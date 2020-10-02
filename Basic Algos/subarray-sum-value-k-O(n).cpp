# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second
# define MEM 8

// bf =>	O(n2 * n) => O(n3)
// efficient => O(n)

int main() {
	fastt; 
	
	int arr[] = {3, 4, 7, 2, -3, 1, 4, 2};
	int n = sizeof(arr)/ sizeof(arr[0]);
	
	int sum[n];
	map<int, int> s;
	int k=7; 
	
	int count=0; 
	sum[0] = arr[0];
	
	for (int i=0; i<n ; i++) {
		if (i!=0) 
			sum[i] = sum[i-1] + arr[i];
		
		if (sum[i]==k) count++;
		if (s.find(sum[i]-k)!=s.end())
			count++;
		
		s.insert(make_pair(sum[i], 1));
	}
	
	cout << count << endl;

	return 0;
}
