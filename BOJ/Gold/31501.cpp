// // DP (small) - G3 - 2024/03/04
// // 이문제는 LIS를 이용해서 풀어야하는 문제
// // 근데 어떻게 푸는지 잘 모르겠으니 내일 다시 도전..!
// // DP(i) + DP2(i) - 1 = ans(i) 이거 맞는데 왜 틀린거지 ㅇㅅㅇ..
// // DP (small) - G3 - 2024/03/04
// #include<iostream>
// #include<algorithm>
// #include<vector>
// #define fastio cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
// #define endl "\n"
// using namespace std;
// int n,q;
// int dp[3001];
// int dp_2[3001];
// int arr[3001];
// int arr_2[3001];
// int ans[3001];
// void DP(int idx){
//     int now = arr[idx];
//     int cnt_1 =1;
//         dp[n-idx+1]=1;
//         for(int j=n-idx+1;j<=n;j++){
//             if(arr[n-idx+1]<arr[j]){
//                 dp[n-idx+1] = max(dp[n-idx+1],dp[j]+1);
//             }
//         }
//         // if(arr[i]>now){
//         //     cnt_1++;
//         //     now = arr[i];
//         // }

//     int cnt_2=1;
//     now = arr_2[idx];
//         dp_2[idx]=1;
//         for(int j=idx;j>=1;j--){
//             if(arr_2[idx]>arr_2[j]){
//                 dp_2[idx] = max(dp_2[idx],dp_2[j]+1);
//             }
//         }
//         // if(arr_2[i]<now){
//         //     cnt_2++;
//         //     now = arr_2[i];
//         // }
//         //ans[idx]=dp[n-idx+1]+dp_2[idx]-1;
//         //cout<<idx<<" "<<dp[idx]<< " "<<dp_2[idx]<<" "<<ans[idx]<<endl;
//     //dp[n] = dp[idx];
//     //dp[n]=0;
//     //ans[idx]=dp[idx]+dp_2[idx]-1;
//     //dp[idx]= cnt_1+cnt_2-1;
//     //cout<<idx<<" "<<dp[idx]<<" "<<dp_2[idx]<<" "<<ans[idx]<<endl;
// }
// int main(){
//     fastio;
//     cin>>n>>q;
//     //for(int i=1; i<=3000;i++)dp[i]=-1;
//     for(int i=1; i<=n;i++) {cin>>arr[i];arr_2[i]=arr[i];}
//     for(int i=1; i<=n; i++){
//         DP(i);
//     }
//     for(int i=1; i<=n; i++){
//         ans[i]=dp[i]+dp_2[i]-1;
//         cout<<i<<" "<<dp[i]<<" "<<dp_2[i]<<" "<<ans[i]<<endl;
//     }
//     while(q--){
//         int t;cin>>t;
//         cout<<dp[t]<<endl;
//     }
// }

// 다풀었당 후후..
// DP (small) - G3 - 2024/03/04
// DP(i) + DP2(i) - 1 = ans(i)
#include<iostream>
#include<algorithm>
#include<vector>
#define fastio cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define endl "\n"
using namespace std;
int n,q;
int dp[3001];//dp[i] = i번째 원소를 마지막으로 하는 LIS의 길이
int dp_2[3001];//dp_2[i] = i번째 원소를 시작으로 하는 LIS의 길이
int arr[3001];//입력받은 배열
int arr_2[3001];
int ans[3001];
void DP(int idx){//idx번째 원소를 마지막으로 하는 LIS의 길이를 구하는 함수
    dp[n-idx+1]=1;//dp[n-idx+1] = 1로 초기화
    for(int j=n-idx+1;j<=n;j++){
        if(arr[n-idx+1]<arr[j]){//만약 arr[n-idx+1]보다 큰 원소가 있다면
            dp[n-idx+1] = max(dp[n-idx+1],dp[j]+1);//dp[n-idx+1]을 갱신
        }
    }
    dp_2[idx]=1;//dp_2[idx] = 1로 초기화
    for(int j=idx;j>=1;j--){
        if(arr_2[idx]>arr_2[j]){
            dp_2[idx] = max(dp_2[idx],dp_2[j]+1);
        }
    }
}
int main(){
    fastio;
    cin>>n>>q;
    for(int i=1; i<=n;i++) {cin>>arr[i];arr_2[i]=arr[i];}
    for(int i=1; i<=n; i++)DP(i);
    for(int i=1; i<=n; i++)ans[i]=dp[i]+dp_2[i]-1;
    while(q--){
        int t;cin>>t;
        cout<<ans[t]<<endl;
    }
}