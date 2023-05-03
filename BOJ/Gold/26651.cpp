// 팬램그 - G5 - 2023/05/03
// 그램팬이 더 어려움.. 이건 마지막 else 부분의 어떻게 분배할까 생각하는게 관건임

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<typeinfo>
#define ll long long
using namespace std;
ll x,acnt=1,zcnt=1,ans=1;
string alpha="BCDEFGHIJKLMNOPQRSTUVWXY";
// void check(ll a, ll z){
//     ll tmp1 = ans+ (a+1)*z;
//     ll tmp2 = ans+ a*(z+1);
//     if(tmp1>x){
        
//     }
//     if(tmp1<x){
        
//     }
//     if(tmp1 == x){
        
//     }
//     if(tmp2>x){
        
//     }
//     if(tmp2<x){
        
//     }
//     if(tmp2==x){
        
//     }
// }
int main(){
    while(1){
    cin>>x;
    if(x==0){cout<<"A"<<endl;exit(0);}
    else if(x==1){cout<<'A'<<alpha<<'Z'<<endl;exit(0);}
    else{
        /*
        x가 딱 떨어지는 제곱수면 while을 한번돌고 끝나지만, 딱 안떨어지는 제곱수면 저 구조상 언젠간 딱 떨어지는 x로 바뀔수 밖에 없음. 
 -> x가 가장 컸을때 이미 그 수의 제곱근의로 각각 A,Z를 분배하니까 길이제한 안에 들어올 것이다! 라고 생각하면 충분히 시간 안에 들어올만한 풀이
        */
        while(x){
            ll xx=sqrt(x);
            x-= xx*xx;
            for(ll i=0;i<xx;i++) cout<<'A';
            cout<<alpha;
            for(ll i=0;i<xx;i++) cout<<'Z';
        }
     }
    }
}
    // else{
    //     //cout<<type(sqrt(x))<<endl;
    //     for(ll i =round(sqrt(x)) ; i>=1;i--){
    //         for(ll j=i; j>=1;j--){
    //             if(i*j == x){
    //                 for(ll t =0 ; t<i;t++)cout<<'A';
    //                 cout<<alpha;
    //                 for(ll t=0;t<j;t++)cout<<'Z';
    //                 exit(0);
    //             }
    //         }
    //     }
    //     cout<<'A'<<alpha;
    //     for(ll i=0 ; i<x;i++){
    //         cout<<'Z';
    //     }
    //  }
    

