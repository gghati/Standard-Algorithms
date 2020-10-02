#include <bits/stdc++.h>
using namespace std;

int main() {
   set<int> Set;
   //insert values in set
    Set.insert(10);
    Set.insert(20);
    Set.insert(30);

   cout<<"Elements are: ";
   //display values
   set<int> :: iterator i;
   for (i = Set.begin(); i != Set.end(); ++i)
      cout << *i << " ";
   //size of set
   cout<<"\nThe size of set : "<<Set.size();
  
    return 0;
}


//Elements are: 10 20 30  
//The size of set : 3