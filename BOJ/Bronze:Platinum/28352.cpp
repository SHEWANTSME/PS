// 10! - B4 - 2023/07/24
// 간만에 브론즈
#include<iostream>
#define ll long long 
using namespace std;
int n;
ll t;
int main(){
    cin>>n;
    t=6;
    if(n==10)cout<<6<<endl;
    else{
        for(int i=n ; i>10; i--)
            t*=i;
        cout<<t<<endl;
    }
}