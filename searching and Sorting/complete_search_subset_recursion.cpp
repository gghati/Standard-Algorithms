# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second


void print_vector(vector<int> arr){
	for(int i: arr) cout << i << " ";
	cout << endl;
}

void search(vector<int> sub, vector<int> arr, int k){
	if(k>=arr.size()){
		print_vector(sub);
	} else {
		// yes taken that element
		sub.push_back(arr[k]);
		//taken then moved to next element in array
		search(sub, arr, k+1);
		
		
		// no not taken that element
		sub.pop_back();
		//not taken then moved to next element
		search(sub, arr, k+1);		
	}
}

int main(){
	vector<int> arr = {5, 23, 345, 88, 77};
	vector<int> sub;
	search(sub, arr, 0);
}

/*

OUTPUT:

5 23 345 88 77 
5 23 345 88 
5 23 345 77 
5 23 345 
5 23 88 77 
5 23 88 
5 23 77 
5 23 
5 345 88 77 
5 345 88 
5 345 77 
5 345 
5 88 77 
5 88 
5 77 
5 
23 345 88 77 
23 345 88 
23 345 77 
23 345 
23 88 77 
23 88 
23 77 
23 
345 88 77 
345 88 
345 77 
345 
88 77 
88 
77 



*/
