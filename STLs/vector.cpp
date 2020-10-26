#include <iostream> 
#include <vector> 
  
using namespace std; 
  
int main() 
{ 
    vector<int> v; 
  
    for (int i = 1; i <= 5; i++) 
        v.push_back(i); 
    
    //treating vector as arrays
    for(int i=0; i<5; i++)
        cout<<v[i]<<" ";

    //using iterators for traversing vector
    for(auto i=v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";

    
    //iterators pointing to end of vectors pronting it in reverse order
    for (auto i = v.crbegin(); i!= v.crend(); ++i) 
        cout << *i << " "; 

    //output 
    //1 2 3 4 5
    //1 2 3 4 5
    //5 4 3 2 1
  
    return 0; 
} 
