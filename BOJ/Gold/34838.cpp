// 삼각형 그리기 - G5 - 2025.12.15
#include<iostream>
#define ll long long
using namespace std;
ll n;
ll ans;
int main(){
    cin>>n;
    if(n==3){cout<<1<<endl;exit(0);}
    else{
        ans=n*(n-1)*(n-2)/6;   
        if(n%3==0) ans=(ans-n/3)/n+1;
        else ans=ans/n;
        cout<<ans<<endl;
    }
}