//Строганова С., 105
//Задача 9.2
#include <iostream> 
#include <cstring> 
#include <string> 
using namespace std; 
struct rec_ 
{ 
     
        int L;
        char* cp;  
}; 

void Invert(rec_& Record) {
    char* rev = new char[Record.L + 1]; 
    rev[Record.L] = '\0'; 
    for (int i = 0; i < Record.L; i++) { 
        rev[i] = Record.cp[Record.L - i - 1]; 
    } 
    strcpy(Record.cp,rev); 
    delete[]rev; 
} 
 
 
 
 
struct rec_ Create(const char* S, int Len) { 
    struct rec_ Output; 
    Output.cp = new char[Len + 1]; 
    strncpy(Output.cp, S, Len); 
    Output.L = Len; 
    return Output; 
} 
 
 
int main() { 
    int number_strings; 
    cout << "Enter the number of strings" << endl; 
    cin >> number_strings; 
    cin.get(); 
 
    for (int i = 0; i < number_strings; i++) { 
        char* str = new char[256]; 
        rec_ x; 
         
        cin.getline(str,256); 
        //cout << str << '\n'; 
        x = Create(str, std::strlen(str));
        Invert(x);
        cout << x.cp<<endl; 
        delete[]x.cp; 
        delete[]str; 
    } 
 
}