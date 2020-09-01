# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long
# define ff first
# define ss second


int main(){
    fastt;
    
	int N, Q;
	cin >> N >> Q;
	
	int arr[1000000+2] = {0};
	set<int> subarr;
	
	subarr.insert(1);
	for(int i=1; i<=N; i++){
		int val; cin >> val;
		if(i!=1 && val%arr[i-1]!=0)
			subarr.insert(i);
			
		arr[i] = val;
	}
	
	for(int i=0; i<Q; i++){
		int A; cin >> A;
		if(A==1) {
			int B, C;
			cin >> B >> C;
			arr[B] = C;				
			
			if (B==1) {
				bool withr= (arr[B+1] % C == 0);
				if(withr)
					subarr.erase(B+1);
				else subarr.insert(B+1);
			}
			
			if (B==N) {
				bool withl= (C % arr[B-1] == 0);
				if(withl)
					subarr.erase(B);
				else subarr.insert(B);
			}
			
			if(B<N && B>1){
				bool withl= (C % arr[B-1] == 0);
				bool withr= (arr[B+1] % C == 0);
				
				if (!withl && withr) {
					subarr.erase(B+1);
					subarr.insert(B);
				} else if (!withl && !withr) {
					subarr.insert(B+1);
					subarr.insert(B);
				} else if(withl && !withr){
					subarr.erase(B);
					subarr.insert(B+1);
				} else if (withl && withr) {
					subarr.erase(B+1);
					subarr.erase(B);
				}
			}

		} else {
			
			int B; cin >> B;
			set<int>::iterator val = subarr.upper_bound(B);
			val--;
			cout << *val << "\n";
		}
	}
}

