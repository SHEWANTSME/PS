//쉬운 정렬 문제 - G5 - 2025.12.02
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll n,k;
vector<ll>arr;
vector<ll>v;
bool flag=0;
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        ll a;cin>>a;
        arr.push_back(a);
    }
    v=arr;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        if(flag)break;
        ll tmp = abs(arr[i]-v[i]);
        if(tmp>k) flag=1;
    }
    if(flag)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}