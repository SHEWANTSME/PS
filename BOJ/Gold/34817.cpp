//쉬운 정렬 문제 - G5 - 2025.12.02
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,k;
vector<int>arr;
int main(){
    cin>>n>>k;
    for(int i=0; i<n; i++){
        int t;cin>>t;arr.push_back(t);
    }
    int now = arr[0];
    for(int i=1; i<n; i++){
        if(now>arr[i]+k){cout<<"NO"<<endl; exit(0);}
        now=max(now,arr[i]);
    }
    cout<<"YES"<<endl;
}