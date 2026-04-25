// A+B - 10 (제1편) - B3 - 2026.04.25
#include <iostream>
using namespace std;
int main(){
    int a=1;
    while(1){
        cout << "? A " << a << endl;
        int resp; cin >> resp;
        if (resp == 1) break;
        a++;
    }
    int b=1;
    while(1){
        cout << "? B " << b << endl;
        int resp; cin >> resp;
        if (resp == 1) break;
        b++;
    }
    cout<<"! "<<a+b<<endl;
}