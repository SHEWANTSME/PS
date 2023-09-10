//점수를 최대로 - S4 - 2023/09/09
#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
int n,m;
ll dp[300001];
vector<ll>v;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll t;cin>>t;
        dp[i]=dp[i-1]+t;
        v.push_back(dp[i]);
    }
    sort(v.begin(),v.end(),greater<ll>());
    ll ans=0;
    for(int i=0;i<m;i++)
        ans+=v[i];
    cout<<ans<<endl;
}