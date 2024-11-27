//벌집 - B2 - 2024/11/26
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll n;
int main(){
    cin>>n;
    if(n==1){cout<<1<<endl;exit(0);}
    if(n>=2 and n<=7){cout<<2<<endl;exit(0);}
    ll tmp_1=2;
    ll tmp_2=7;
    for(ll i=2;;i++){
        tmp_1 = tmp_2+1;
        tmp_2 = (6*i)+tmp_1-1;
        if(n>=tmp_1 and n<=tmp_2){
            cout<<i+1<<endl;exit(0);
        }
    }
}