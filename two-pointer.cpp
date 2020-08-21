# include <bits/stdc++.h>
using namespace std;
# define fastt ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)
# define testt int T; cin>>T; while(T--)
# define ll long long


int main(){
    fastt;
    testt{
    
    	int N, K;
    	cin >> N >> K;
    	
    	int A[N];
    	for (int i=0; i<N; i++)
    		cin >> A[i];
    		
    	int fre[K+1] = {0};
    	
    	fre[A[0]]=1;
    	int l=0, r=0;
	int count=1;    	
    	int max_len=1;
    	
    	while(true){
    		while(++r<N && count<K){
    			if(fre[A[r]] == 0) count++;
    			fre[A[r]]++;
    			if(count<K) max_len = max(max_len, r-l+1);
	    	}
    		
    		if(r==N) break;
    		r--;
    		
    		while(l<=r && count==K){
	    		if(fre[A[l]]==1) count--;
    			fre[A[l]]--;
    			l++;
    		}
    		
    	}
    	
    	cout << max_len << "\n";
    }
}
