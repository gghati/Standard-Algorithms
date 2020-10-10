//Maximum area of histogram
//each element of array denotes the size of the bar.You have to find the max area of histogram.
//input : 6 2 5 4 5 1 6
//output : 12
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int>v1;
	vector<int>v2;
	stack<int>s1;
	stack<int>s2;
	int count1 = 1;
	int count2 = 1;
	int arr2[n];
//next smaller element
	for (int i = 0; i < n; i++) {
		if (s1.size() == 0) v1.push_back(1);
		else if (s1.top() < arr[i]) v1.push_back(1);
		else {
			while (s1.size() > 0 && s1.top() >= arr[i]) {
				s1.pop();
				count1++;
			}
			v1.push_back(count1);
		}
		s1.push(arr[i]);
	}

	for (int i = n - 1; i >= 0; i--) {
		if (s2.size() == 0) v2.push_back(1);
		else if (s2.top() < arr[i]) v2.push_back(1);
		else {
			while (s2.size() > 0 && s2.top() >= arr[i]) {
				s2.pop();
				count2++;
			}
			v2.push_back(count2);
		}
		s2.push(arr[i]);
	}
	reverse(v2.begin(), v2.end());

	for (int i = 0; i < n; i++) arr2[i] = (v1[i] + v2[i]) * arr[i];
	sort(arr2, arr2 + n);
	cout << arr2[n - 1];

}