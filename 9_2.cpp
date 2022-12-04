#include <iostream>
#include <string.h>
using namespace std;
struct rec_{
    int L;
    char* cp = (char*)malloc((L+1)*sizeof(char));};

struct rec_ Invert(rec_ &Record){
    char* rev = (char*)malloc(Record.L+1);
    for(int i = 0; i<=Record.L; i++){
        rev[i]= Record.cp[Record.L-i];
        cout<<rev[i];
    }
    struct rec_ Output;
    Output.cp = rev;
    Output.L = Record.L;
    return Output;
    }

struct rec_ Create(const char* S, int Len){
    struct rec_ Output;
    strncpy(Output.cp, S, Len);
    Output.L = Len;
    return Output;
}

int main(){
    int number_strings;
    cout<<"Enter the number of strings\n";
    cin>>number_strings;
    rec_ *mas;
    mas = new rec_[number_strings];
    for(int i =0; i<=number_strings; i++){
        char* str = new char[255];
        cin.getline(str, 255);
        mas[i] = Create(str, strlen(str));
        cout<<Invert(mas[i]).cp<<"\n";
    }
    delete []mas;
}