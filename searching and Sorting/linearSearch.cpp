#include <iostream> 
using namespace std; 
  
void linearSearch(int arr[], int n, int x) 
{  
    for (int i = 0; i < n; i++) 
        if (arr[i] == x) 
            cout<<"Element found at index"<<" "<<i<<endl;
} 
  
int main() 
{ 
    int arr[] = { 6, 1, 8, 10, 4 }; 
    int x = 10; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    linearSearch(arr, n, x); 
   return 0; 
} 

//sample
//Element Found at index 3