//Строганова С., 105
//задача 9.1

#include <iostream>
#include "9_1_1.h"
#include <cmath>
#include <string>
using namespace std;
int main(){
    float b;
    cout<<"Hello"<<endl<<"Enter real number:";
    cin >>b;
    cout<<b<<endl;
    cout<<"custom sinus:"<<sinus:: sin(b)<< endl;
    cout <<"default sinus:"<<sin(b) << endl;
}