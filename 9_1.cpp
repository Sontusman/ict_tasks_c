//Строганова С., 105
//задача 9.1

#include <iostream>
#include "9_1_1.h"
#include <cmath>
using namespace std;
int main(){
    float b;
    char act[][35]={"Hello", "Enter real number"};
    int amount = sizeof(act)/sizeof(act[0]);
    type(act, amount);
    cin >>b;
    cout<<b<<endl;
    cout<<"custom sinus:"<<sinus:: sin(b)<< endl;
    cout <<"default sinus:"<<sin(b) << endl;
}