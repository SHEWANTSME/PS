// 밤양갱 - S1 - 2024.05.27
#include<iostream>
#define ll unsigned long long 
using namespace std;
int main(){
    ll n;
    cin>>n;
    if (n==1) {cout<<10<<endl;exit(0);}
    if (n==2 or n==3) {cout<<11<<endl;exit(0);}
    // n==3일때 11이 생각보다 어려웠음
    // daldidalgo -> 8 + daldidalgo -> 1  + daldidalgodaldida -> 1 + n ->1 = 11
    //if (n>=4 and n<8) {cout<<12<<endl;exit(0);}
    ll iter=2;
    ll cnt=1;
    while(1){// 규칙대로 찾아서 찾으면 됨
        iter*=2;cnt+=1;
        if (n>=iter/2 && n<iter) {
            cout << 8 + cnt + 1 << endl;exit(0);
        }
    }
}