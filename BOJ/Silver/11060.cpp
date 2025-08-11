// 점프 점프 - S2 - 2025.08.11
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int arr[1002];
int dp[1002][1002];
int main(){
    cin>>n;
    for(int i=1; i<=n; i++)cin>>arr[i];
    if(n==1){cout<<0<<endl;exit(0);}
    if(arr[1]==0){cout<<-1<<endl;exit(0);}
    for(int i=0;i<=1001;i++)
        for(int j=0; j<=1001; j++)
            dp[i][j] = 1000;
        
    dp[1][1]=0;
    for(int i=2; i<=min(n,1+arr[1]);i++)dp[1][i]=1;
    int cnt = 1;
    for(int i=2; i<=n; i++){
        for(int j=1; j<i; j++){
            if(dp[j][i]==1000)continue;
            int now = arr[i];
            for(int k=i+1; k<=min(n,i+now); k++){
                dp[i][k] = min(dp[i][k],dp[j][i]+1);
            }
        }
    }
    int ans = 1000;
    for(int i=1; i<n; i++){
        ans = min(ans, dp[i][n]);
    }
    if(ans==1000)cout<<-1<<endl;
    else cout<<ans<<endl;
}