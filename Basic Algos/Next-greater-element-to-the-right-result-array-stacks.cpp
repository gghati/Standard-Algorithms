//find the next greater element to right of the given element and form an array of results - Standard question asked in interviews.
//n=6
//input array : 2 1 3 4 5 6
//output array : 3 3 4 5 6 -1
//exp : next greatest to 2 to its right is 3.... for 1 also its 3...for 3 its 4 and so on.


#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	vector<int>v;
	stack<int>s; //declaration of stack
	for (int i = n - 1; i >= 0; i--) {
		if (s.size() == 0) v.push_back(-1); //initially when stack is empty we push -1
		else if (s.size() > 0 && s.top() > arr[i]) v.push_back(s.top()); //we push top element when its greater than given element
		else if (s.size() > 0 && s.top() <= arr[i]) { //if given element is greater than top element we run a while loop and then find next big
			while (s.size() > 0 && s.top() <= arr[i]) s.pop();
			if (s.size() == 0) v.push_back(-1);
			else v.push_back(s.top());
		}
		s.push(arr[i]);
	}
	reverse(v.begin(), v.end());
	for (int i = 0; i < n; i++) cout << v[i] << " ";
	return 0;
}