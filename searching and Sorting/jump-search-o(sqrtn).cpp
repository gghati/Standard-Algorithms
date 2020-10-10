#include <iostream>
#include <bits/stdc++.h> 
#define MAX 500

using namespace std;

int jumpSearch(int array[],int x,int n){
  int st=sqrt(n);
  int prev=0;
  while(array[min(st,n)-1]<x){
    prev=st;
    st+=sqrt(n);
    if(prev>=n)
       return -1;
  }
  while(array[prev]<x){
    prev++;
    if(prev==min(st,n))
      return -1;
  }
  
  if(array[prev]==x)
  {
    return prev;
  }
  return -1;
}
int main(){
  int arr[MAX];
  cout<<"Enter the number of array elements: ";
  int n,search;
  cin>>n;
  for(int i=0;i<n;i++)   
    cin>>arr[i];
  cout<<"Enter the element to be searched: ";
  cin>>search;
  int index=jumpSearch(arr,search,n);
  if(index==-1)
  cout<<"Element not found";
  else
  cout<<"The element is at index "<<index;

  return 0;

}