// 연속합2 - G5 - 2024.05.07
// 연속합은 now vs 이전값까지의 누적합+now 을 비교해서 큰 값 저장하면 되고
// 한번 끊긴 합은 조금 어려운데, 현재 상태가 이미 한번 끊겼는지, 아니면 쭉 온건지에 따라 다름
// 한번 끊긴 상태에서의 이전까지의 누적합 + now vs 끊긴 적 없는 상태의 이전값 을 비교해야함

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int arr[100001];
int dp[100001][2];// 0: 연속합, 1: 끊어서 합
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    dp[1][0]=arr[1];
    dp[1][1]=arr[1];
    int ans=arr[1];
    for(int i=2;i<=n;i++){
        dp[i][0]=max(dp[i-1][0]+arr[i],arr[i]);
        dp[i][1]=max(dp[i-1][0],dp[i-1][1]+arr[i]); // 이 두번째 DP 구하는게 핵심
        // dp[i][1]은 이전값까지의 누적합+현재값 vs 끊긴적 없는 상태의 이전값
        ans=max(ans,max(dp[i][0],dp[i][1]));
    }
    // for(int i=1; i<=n;i++){
    //     for(int j=0;j<2;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<ans<<endl;
}