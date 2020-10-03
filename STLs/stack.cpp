#include <bits/stdc++.h> 

using namespace std;


//function to display stack
void display(stack <int> s)
{
    while (!s.empty())
    {
        cout << '\t' << s.top();
        s.pop();
    }
    cout << '\n';
}

int main ()
{
    stack <int> s;
    //pushing values in stack
    s.push(1);
    s.push(0);
    s.push(2);

    cout << "The stack is : ";
    display(s);

    //size of stack
    cout << "\nsize: " << s.size();
    //top of stack
    cout << "\ntop: " << s.top();
     //pop from stack
    cout << "\npop : ";  s.pop();
   
    //display after pop
    cout << "The stack is : ";
    display(s);
    return 0;
}

//the stack is : 2 0 1
//size: 3
//top: 2
//pop: 2
//the stack is :0 1