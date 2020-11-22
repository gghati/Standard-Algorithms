#include <iostream>
using namespace std;

double gcd(int f_num, int s_num);

int main (void){
    double f_num = 0, s_num = 0; char consent = 'n';
    do{
        cout << "Please enter a first number: ";
        cin >> f_num;
        cout << "Please enter a second number: ";
        cin >> s_num;

        cout << "GCD is: " << gcd(f_num, s_num) << endl;
        cout << endl << "Do you want to continue [y/n]: ";
        cin >> consent;
        cout << endl;
    }while (consent == 'y');

    return 0;
}

double gcd(int f_num, int s_num){
    if (f_num < s_num){
        if (s_num % f_num == 0) return f_num;
        return gcd(f_num, s_num % f_num);
    }
    else{
        if (f_num % s_num == 0) return s_num;
        return gcd(s_num, f_num % s_num);
    }
}
