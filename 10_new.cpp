//Строганова С., 105
//Задача 10
#include <iostream> 
#include <string> 
using namespace std; 
struct Time {  
    int h;  
    int m;  
}; 
struct xTime {  
    double h;  
    double m;  
}; 
 
template <typename T1, typename T2> 
void Input(T1& a, T2& b, string Output = "Input 2 values:") { 
    cout << Output << "\n"; 
    cin >> a; 
    cin >> b; 
} 
Time SetTime(int h = 0, int m = 0) { 
    Time Output; 
    Output.h = h; 
    Output.m = m; 
    return Output; 
} 
xTime SetxTime(double h = 0, double m = 0) { 
    xTime Output; 
    Output.h = h; 
    Output.m = m; 
    return Output; 
} 
template <typename T1, typename T2> 
T2 Add(T1 time1, T2 time2) { 
    T2 Output; 
    Output.h = time1.h + time2.h; 
    Output.m = time1.m + time2.m; 
    return Output; 
} 
template <typename T> 
void Reset(T& time) { 
    time.h = 0; 
    time.m = 0; 
} 
template <typename T> 
void Print(T time1, string comment = "") { 
    cout << comment << endl << "hour:" << time1.h << " min:" << time1.m << endl; 
} 
 
int main() { 
    int a, b; 
    Input(a, b, "Give me 2 integers:\n"); 
    Time t1 = SetTime(a, b); 
    Time t2 = SetTime(a); 
    Time t3 = SetTime(); 
    t3 = Add(t1, t2); 
    Print(t3, "Let's summarize integers = 2a+b"); 
    Reset(t3); // передача аргумента по ссылке 
    Print(t3); 
 
 
    double x, y; 
    Input(x, y, "Get me reals: x and y"); 
    xTime xt1 = SetxTime(x); 
    xTime xt2 = SetxTime(x, y); 
    xTime xt3 = SetxTime(); 
    xt3 = Add(xt1, xt2); 
    Print(xt3, "Let's summarize doubles = 2x+y"); 
    Reset(xt3); 
    Print(xt3); 
    Input(x, y); 
    cout << x << "---" << y << endl; 
    return 0; 
}