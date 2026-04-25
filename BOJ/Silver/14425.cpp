// 문자열 집합 - S4 - 2026.04.25
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int n,m;
unordered_map<string,int> mp;
int cnt=0;
int main(){
    cin>>n>>m;
    for(int i=1; i<=n ;i++){
        string s; cin>>s;
        mp[s]=1;
    }
    for(int j=1; j<=m; j++){
        string s; cin>>s;
        if(mp[s]==1)cnt++;
    }
    cout<<cnt<<endl;
}