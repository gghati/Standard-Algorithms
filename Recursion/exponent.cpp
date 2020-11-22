#include <iostream>
#include <cmath>
using namespace std;

double exponent(double base, double power);

int main (void){
    double base = 0, power = 0; char consent = 'n';
    do{
        cout << "Please enter a base: ";
        cin >> base;
        cout << "Please enter a power: ";
        cin >> power;

        cout << "The exponent is: " << exponent(base, power) << endl;
        cout << endl << "Do you want to continue [y/n]: ";
        cin >> consent;
        cout << endl;
    }while(consent == 'y');
    return 0;
}

double exponent(double base, double power){
    if (power < 0){return (1/base) * exponent((1/base), abs(power) - 1);} // For negative powers
    if (power == 0){return 1;}                                            // Base case
    return base * exponent(base, power - 1);                              // Recursive call with one less power
}
