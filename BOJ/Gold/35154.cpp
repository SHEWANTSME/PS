// ProblemSolving이 아니에요 - G4- 2026.01.27
#include <iostream>
#include <vector>
#include <string>
#define ll long long
#define endl "\n"
ll dp[5005][5005];// dp[i][j]: i번째 문자까지 처리했을 때, 스택 높이가 j인 경우의 수
using namespace std;
int main() {
    int n; cin>>n;
    dp[0][0]=1;
    for(int i=0;i<=5000;i++){
        for(int j=0;j<=i;j++){
            if(dp[i][j]==0)continue;
            ll now = dp[i][j]%998244353;
            if(j>0) dp[i+1][j-1]=(dp[i+1][j-1]+now)%998244353;//pop
            if(i+2<5005) dp[i+2][j+1]=(dp[i+2][j+1]+now)%998244353;//push
        }
    }
    while(n--){
        int t; cin>>t;
        if(t==1){cout<<-1<<endl;continue;}
        ll ans=0;
        for(int i=0;i<=t;i++){
            if(dp[t][i]>0) ans=(ans+dp[t][i])%998244353;
            ans%=998244353;
        }
        cout<<ans<<endl;
    }
}