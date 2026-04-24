// 맛있는 햄버거 - S5 - 2026.04.25
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int n;
int main(){
    cin>>n;
    ll v=0; ll cur=0;
    while(n--){
        ll t;cin>>t;
        cur=max(cur,t);
        v+=cur;
    }
    if(v%3) cout<<"Oh My God!"<<endl;
    else cout<<"Delicious!"<<endl;
}