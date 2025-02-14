//Dance Dance Revolution - G3 - 2025.02.14
// 2342.md파일도 같이 봐봐
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
vector<int>v;
int dp[100001][5][5];
int cost(int a, int b){
    if(a==0)return 2;
    if(a==b)return 1;
    if(abs(a-b)==2)return 4;
    return 3;
}
int Func(int idx, int l, int r){
    if(idx==v.size())return 0;
    if(dp[idx][l][r]!=-1)return dp[idx][l][r];
    int nxt = v[idx];
    int res = 987654321;
    if(nxt != r) res = min(res,cost(l,nxt)+Func(idx+1,nxt,r));
    if(nxt != l) res = min(res,cost(r,nxt)+Func(idx+1,l,nxt));
    return dp[idx][l][r] = res;
}
int main(){
    while(1){
        int n;cin>>n;
        if(n==0)break;
        v.push_back(n);
    }
    memset(dp,-1,sizeof(dp));
    int ans = Func(0,0,0);
    cout<<ans<<endl;
}